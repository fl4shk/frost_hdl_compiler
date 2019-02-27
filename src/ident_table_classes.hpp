#ifndef src_ident_table_classes_hpp
#define src_ident_table_classes_hpp

// src/ident_table_classes.hpp

#include "misc_includes.hpp"

namespace frost_hdl
{

//typedef std::string* Ident;

template<typename Type>
class IdentTable
{
public:		// typedefs
	typedef SavedString Ident;

private:		// variables
	std::map<Ident, Type> _table;

public:		// functions
	inline IdentTable()
	{
	}

	// Type accessors
	inline Type& at(Ident some_name)
	{
		return _table[some_name];
	}

	inline const Type& at(Ident some_name) const
	{
		return _table.at(some_name);
	}

	inline bool contains(Ident some_name) const
	{
		return (_table.count(some_name) == 1);
	}

	inline void insert_or_assign(const Type& to_insert_or_assign)
	{
		at(to_insert_or_assign.name()) = to_insert_or_assign;
	}
	inline void insert_or_assign(Type&& to_insert_or_assign)
	{
		at(to_insert_or_assign.name()) = std::move(to_insert_or_assign);
	}

	GEN_GETTER_BY_CON_REF(table);
};

template<typename Type>
class IdentToPointerTable
{
public:		// typedefs
	typedef SavedString Ident;

private:		// variables
	std::map<Ident, Type*> _table;

public:		// functions
	inline IdentToPointerTable()
	{
	}

	// Type accessors
	inline auto& at(Ident some_name)
	{
		return _table[some_name];
	}

	inline const auto& at(Ident some_name) const
	{
		return _table.at(some_name);
	}

	inline bool contains(Ident some_name) const
	{
		return (_table.count(some_name) == 1);
	}

	inline void insert_or_assign(Type* to_insert_or_assign)
	{
		at(to_insert_or_assign->name()) = to_insert_or_assign;
	}

	GEN_GETTER_BY_CON_REF(table);
	GEN_GETTER_BY_REF(table);
};

} // namespace frost_hdl

#endif		// src_ident_table_classes_hpp
