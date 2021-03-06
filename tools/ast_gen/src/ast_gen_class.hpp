#ifndef src_ast_gen_class_hpp
#define src_ast_gen_class_hpp

// src/ast_gen_class.hpp

#include "misc_includes.hpp"
#include "src_code_chunk_class.hpp"

enum class Tok
{
	Comment,
	Colon,
	Semicolon,
	Comma,
	Ident,
	Unknown,
	Done,
};
extern const std::map<Tok, string> tok_ident_map;

class Lexer final : public LexerBase<Tok>
{
public:		// functions
	Lexer(const string& s_filename, string* s_text);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Lexer)
	~Lexer();

	void next_tok();
	inline auto src_code_chunk(const TwoStates* two_states=nullptr) const
	{
		return LexerBase<Tok>::src_code_chunk<SrcCodeChunk>(two_states);
	}

private:		// functions
	void _inner_next_tok();
};

class AstGen final : public StatefulParserBase<Lexer>
{
public:		// types
	using Base = StatefulParserBase<Lexer>;
	using TokSet = std::set<Tok>;

	friend Base;

	class Var final
	{
	public:		// variables
		string type, ident;
		bool init;

	public:		// functions
		Var() = default;
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Var);
		~Var() = default;
		inline bool operator == (const Var& to_cmp) const
		{
			return ((type == to_cmp.type) && (ident == to_cmp.ident));
		}
		inline bool operator != (const Var& to_cmp) const
		{
			return (!((*this) == to_cmp));
		}
		inline bool is_protected() const
		{
			return (ident.at(0) == '_');
		}
		inline string init_ident() const
		{
			if (is_protected())
			{
				return sconcat("s", ident);
			}
			else
			{
				return sconcat("s_", ident);
			}
		}
	};

	class Node final
	{
	public:		// variables
		string ident, extends;
		std::vector<string> children;
		std::vector<Var> var_vec;
		std::set<string> child_ident_set, var_ident_set;
	
	public:		// functions
		Node() = default;
		GEN_MOVE_ONLY_CONSTRUCTORS_AND_ASSIGN(Node);
		~Node() = default;
	};

	class WTab final
	{
	public:		// variables
		std::variant<AstGen*, WTab*> parent;

	public:		// functions
		inline WTab(AstGen* s_parent)
			: parent(s_parent)
		{
		}
		inline WTab(WTab* s_parent)
			: parent(s_parent)
		{
		}
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(WTab);
		~WTab() = default;

		template<typename... ArgTypes>
		inline string run(ArgTypes&&... args) const
		{
			if (std::holds_alternative<AstGen*>(parent))
			{
				return sconcat("\t", args...);
			}
			else
			{
				return sconcat("\t", std::get<WTab*>(parent)->run
					(args...));
			}
		}
	};

//public:		// constants
//	static const string node_base_str, node_list_str;

private:		// variables
	std::vector<Node> _node_vec;
	std::set<string> _node_ident_set;
	std::map<string, size_t> _node_ident_map;

public:		// functions
	AstGen(std::vector<string>&& s_filename_vec);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstGen)
	~AstGen();

	void run();

private:		// functions
	std::vector<string> _extended_children(const Node& node) const;
	std::vector<Var> _extended_var_vec(const Node& node) const;
	bool _extends_from_list(const Node& node) const;
	void _write_node_to_cxx_source_file(std::ofstream& f,
		const Node& node);
	inline std::string _msg_for_expect(Tok tok,
		const LexerState& lex_state) const
	{
		return Base::_msg_for_expect(tok, tok_ident_map, lex_state);
	}
	inline void _expect(Tok tok, const LexerState& lex_state)
	{
		Base::_expect(tok, tok_ident_map, lex_state);
	}
	inline void _expect(Tok tok)
	{
		_expect(tok, _lexer().state());
	}
	inline auto _wexpect(TokType tok, Lexer* lexer=nullptr)
	{
		return Base::_wexpect(tok, tok_ident_map, lexer);
	}
	inline void _unexpected(const LexerState& lex_state)
	{
		Base::_unexpected(tok_ident_map, lex_state);
	}
	inline void _unexpected()
	{
		_unexpected(_lexer().state());
	}
	inline void _unexpected(Lexer* lexer)
	{
		Base::_unexpected(tok_ident_map, lexer);
	}
	inline bool _to_next_in_list(Tok end, Tok separator=Tok::Comma)
	{
		return Base::_to_next_in_list(end, separator, tok_ident_map);
	}
	inline void _next_lss_tokens()
	{
		Base::_next_lss_tokens(tok_ident_map);
	}
	bool _check_prefixed_tok_seq(const TokSet& prefix_set, Tok end)
	{
		return Base::_check_prefixed_tok_seq(prefix_set, end);
	}
	bool _check_prefixed_tok_seq(Tok end)
	{
		return Base::_check_prefixed_tok_seq(TokSet(), end);
	}
	inline auto _lex_tok() const
	{
		return _lexer().tok();
	}
	inline void _next_tok()
	{
		_lexer().next_tok();
	}
	template<typename FirstFuncType, typename... RemFuncTypes>
	bool _opt_parse(FirstFuncType&& first_func,
		RemFuncTypes&&... rem_funcs)
	{
		return Base::_opt_parse(this, first_func, rem_funcs...);
	}
	template<typename FirstFuncType, typename... RemFuncTypes>
	void _req_parse(FirstFuncType&& first_func,
		RemFuncTypes&&... rem_funcs)
	{
		Base::_req_parse(this, first_func, rem_funcs...);
	}
	template<typename FirstFuncType, typename... RemFuncTypes>
	void _req_parse_loop(FirstFuncType&& first_func,
		RemFuncTypes&&... rem_funcs)
	{
		Base::_req_parse_loop(this, first_func, rem_funcs...);
	}

	bool _parse_node();
	bool _parse_extends();
	bool _parse_var();
	bool _parse_child();
};

#endif		// src_ast_gen_class_hpp
