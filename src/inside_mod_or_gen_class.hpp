#ifndef src_inside_mod_or_gen_class_hpp
#define src_inside_mod_or_gen_class_hpp

// src/inside_mod_or_gen_class.hpp

#include "misc_includes.hpp"
#include "symbol_class.hpp"
#include "frost_function_class.hpp"
#include "frost_full_type_class.hpp"

namespace frost_hdl
{

class InsideModOrGen
{
protected:		// variables
	// This is intended to be used for searching for symbols in the
	// "ParseTreeVisitor"
	std::variant<FrostModule*, FrostGenerate*> _parent;

public:		// variables
	SymbolTable local_symbol_table;
	FrostLhsTypeTable frost_lhs_type_table;
	FrostFullTypeTable frost_full_type_table;
	FrostFunctionTable frost_function_table;
	FrostStatementTable frost_statement_table;
	FrostGenerateTable frost_generate_table;

public:		// functions
	InsideModOrGen();

	template<typename ParentType>
	inline InsideModOrGen(ParentType* s_parent)
		: InsideModOrGen()
	{
		_parent = s_parent;
	}

	GEN_MOVE_ONLY_CONSTRUCTORS_AND_ASSIGN(InsideModOrGen);

	virtual ~InsideModOrGen();

	GEN_GETTER_BY_CON_REF(parent)
};

} // namespace frost_hdl

#endif		// src_inside_mod_or_gen_class_hpp
