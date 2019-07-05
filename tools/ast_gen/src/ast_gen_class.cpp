#include "ast_gen_class.hpp"

#include <ctype.h>

const std::map<Tok, string> tok_ident_map
= {
	{Tok::Comment, "//"};
	{Tok::Colon, ":"},
	{Tok::Semicolon, ";"},
	{Tok::Comma, ","},
	{Tok::Ident, "ident"},
	{Tok::Unknown, "unknown"},
};
Tok Lexer::next_tok(bool just_test)
{
	if (!just_test)
	{
		return _next_tok_no_test(Tok::Done, Tok::Comment);
	}
	else // if (just_test)
	{
		return Lexer(*this).next_tok(false);
	}
}

void Lexer::_inner_next_tok()
{
	if (c() == '/')
	{
		_set_tok(Tok::Unknown, true);
		if (c() == '/')
		{
			_set_tok(Tok::Comment, true);
			while ((c() != '\n') && (c() != EOF))
			{
				_next_char();
			}
			if (c() == EOF)
			{
				_set_tok(Tok::Done, false);
			}
		}
	}
	else if (c() == ':')
	{
		_set_tok(Tok::Colon, true);
	}
	else if (c() == ';')
	{
		_set_tok(Tok::Semicolon, true);
	}
	else if (c() == ',')
	{
		_set_tok(Tok::Comma, true);
	}
	else if (isalpha(c()) || (c() == '_'))
	{
		{
			string temp;
			temp = static_cast<char>(c());
			_state.set_s(temp);
		}
		_next_char();

		for (; isalnum(c()) || (c() == '_'); _next_char())
		{
			_state.set_s(_state.s() + static_cast<char>(c()));
		}
		_set_tok(Tok::Ident, false);
	}
	else
	{
		_set_tok(Tok::Unknown, true);
	}
}

const string AstGen::node_base_str
	= sconcat("class NodeBase\n",
	"{\n",
	"public:		// types\n",
	"	using TokSet = std::set<Tok>;\n",
	"	using Children = std::map<string, ",
		"std::vector<unique_ptr<NodeBase>>>;\n",
	"	using Child = unique_ptr<NodeBase>;\n",
	"\n",
	"protected:		// variables\n",
	"	SrcCodeChunk _src_code_chunk;\n",
	"	Children _children;\n",
	"\n",
	"public:		// functions\n",
	"	inline NodeBase()\n",
	"	{\n",
	"	}\n",
	"	inline NodeBase(const SrcCodeChunk& s_src_code_chunk)\n",
	"		: _src_code_chunk(s_src_code_chunk)\n",
	"	{\n",
	"	}\n",
	"	GEN_POST_CONSTRUCTOR(NodeBase);\n",
	"\n",
	"	inline bool has(const string& ident) const\n",
	"	{\n",
	"		//return ((children().count(ident) != 0)\n",
	"		//	&& (children().at(ident).front().get() != nullptr));\n",
	"		return (children().at(ident).front().get() != nullptr);\n",
	"	}\n",
	"\n",
	"	inline const Children& children() const\n",
	"	{\n",
	"		return _children;\n",
	"	}\n",
	"\n",
	"	GEN_GETTER_BY_CON_REF(src_code_chunk)\n",
	"\n",
	"protected:		// functions\n",
	"	template<typename FirstType, typename... RemArgTypes>\n",
	"	inline void _add_indiv_children(const string& first_ident,\n",
	"		FirstType&& first_child, RemArgTypes&&... rem_children)\n",
	"	{\n",
	"		_insert_children_list(first_ident);\n",
	"		_children[first_ident].push_back(move(first_child));\n",
	"		if constexpr (sizeof...(rem_children) != 0)\n",
	"		{\n",
	"			_add_indiv_children(rem_children...);\n",
	"		}\n",
	"	}\n",
	"	inline void _insert_children_list(const string& ident)\n",
	"	{\n",
	"		_children[ident] = std::vector<unique_ptr<NodeBase>>();\n",
	"	}\n",
	"	template<typename FirstType, typename... RemArgTypes>\n",
	"	inline void _append_children(const string& ident,\n",
	"		FirstType&& first_child, RemArgTypes&&... rem_children)\n",
	"	{\n",
	"		if (_children.count(ident) == 0)\n",
	"		{\n",
	"			_insert_children_list(ident);\n",
	"		}\n",
	"		_children[ident].push_back(move(first_child));\n",
	"\n",
	"		if constexpr (sizeof...(rem_children) != 0)\n",
	"		{\n",
	"			_append_children(ident, rem_children...);\n",
	"		}\n",
	"	}\n",
	"};\n");

const string AstGen::node_list_str
	= sconcat("class NodeList : public NodeBase\n",
	"{\n",
	"public:		// functions\n",
	"	inline NodeList(const SrcCodeChunk& s_src_code_chunk)\n",
	"		: NodeBase(s_src_code_chunk)\n",
	"	{\n",
	"		_insert_children_list(\"list\");\n",
	"	}\n",
	"	GEN_POST_CONSTRUCTOR(NodeList);\n",
	"\n",
	"	inline void append_list_child(Child&& child)\n",
	"	{\n",
	"		_append_children(\"list\", move(child));\n",
	"	}\n",
	"};\n");


AstGen::AstGen(std::vector<string>&& s_filename_vec)
	: ParserBase<Lexer>(std::move(s_filename_vec))
{
}
AstGen::~AstGen()
{
}

void AstGen::run()
{
	while (_do_one_level_parse(&_parse_node))
	{
	}
}

bool AstGen::_parse_node()
{
	if (just_test())
	{
		return _check_prefixed_tok_seq(Tok::Ident);
	}
	_next_lss_tokens();
	_node_vec.push_back(Node());

	for (const auto& iter : _lss.found_set)
	{
		if (iter.tok() == _lss.end)
		{
			_node_vec.back().ident = iter.s();
		}
	}

	_do_one_level_parse(&_parse_extends);
	while (_do_one_level_parse(&_parse_var, &_parse_child))
	{
	}
	return false;
}
bool AstGen::_parse_extends()
{
	if (just_test())
	{
		return _check_prefixed_tok_seq(Tok::Comma);
	}
	_next_lss_tokens();

	for (const auto& iter : _lss.found_set)
	{
		if (iter.tok() == _lss.end)
		{
			_node_vec.back().extends = iter.s();
		}
	}

	return false;
}
bool AstGen::_parse_var()
{
	return false;
}
bool AstGen::_parse_child()
{
	return false;
}