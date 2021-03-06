#ifndef src_parsed_src_code_class_hpp
#define src_parsed_src_code_class_hpp

// src/parsed_src_code_class.hpp

#include "misc_includes.hpp"
//#include "general_allocator_class.hpp"
#include <ANTLRErrorListener.h>
#include "gen_src/FrostHdlGrammarLexer.h"
#include "gen_src/FrostHdlGrammarParser.h"
#include "gen_src/FrostHdlGrammarVisitor.h"
#include "ptvisitor_error_listener_class.hpp"

namespace frost_hdl
{

class ParsedSrcCode
{
private:		// variables
	//SavedString _filename;
	Ident _filename;
	std::unique_ptr<antlr4::ANTLRInputStream> _input_stream;
	std::unique_ptr<FrostHdlGrammarLexer> _lexer;
	std::unique_ptr<antlr4::CommonTokenStream> _tokens;
	std::unique_ptr<FrostHdlGrammarParser> _parser;
	std::unique_ptr<PTVisitorErrorListener>
		_ptvisitor_error_listener;

public:		// functions
	ParsedSrcCode();

	ParsedSrcCode(const Ident& s_filename);

	GEN_MOVE_ONLY_CONSTRUCTORS_AND_ASSIGN(ParsedSrcCode);
	virtual ~ParsedSrcCode();

	GEN_GETTER_BY_CON_REF(filename)
	GEN_GETTER_BY_CON_REF(parser)
};

} // namespace frost_hdl

#endif		// src_parsed_src_code_class_hpp
