#include "frost_full_type_class.hpp"
#include "expression_class.hpp"
#include "expression_builder_class.hpp"

namespace frost_hdl
{

// Scalar constructor, "_ident" taken from "_frost_lhs_type"
FrostFullType::FrostFullType(const SrcCodePos& s_src_code_pos,
	FrostLhsType* s_frost_lhs_type)
	// Calls the next constructor (which calls the constructor after that)
	: FrostFullType(s_src_code_pos, s_frost_lhs_type->ident(),
	s_frost_lhs_type, nullptr)
{
}
// Array constructor, "_ident" taken from "_frost_lhs_type" and
// "s_right_dim_expr"
FrostFullType::FrostFullType(const SrcCodePos& s_src_code_pos,
	FrostLhsType* s_frost_lhs_type, Expression* s_right_dim_expr)
	// Calls the next constructor
	: FrostFullType(s_src_code_pos,
	construct_initial_type_ident_from_pointer(s_frost_lhs_type->ident(),
	s_right_dim_expr), s_frost_lhs_type, s_right_dim_expr)
{
}
FrostFullType::FrostFullType(const SrcCodePos& s_src_code_pos,
	SavedString s_ident, FrostLhsType* s_frost_lhs_type,
	Expression* s_right_dim_expr)
	: HasSrcCodePosAndIdentBase(s_src_code_pos, s_ident),
	_frost_lhs_type(s_frost_lhs_type), _right_dim_expr(s_right_dim_expr)
{
}

//bool FrostFullType::operator == (const FrostFullType& other) const
//{
//	// The addresses of two "FrostLhsType"s *must* be the same in all
//	// cases for them to be the same researcher, even for built-in
//	// "FrostLhsType"s.
//	// 
//	// This is stronger type checking than SystemVerilog has.
//	if (_frost_lhs_type == other._frost_lhs_type)
//	{
//		if (_right_dim_expr == other._right_dim_expr)
//		{
//			return true;
//		}
//		else if (is_array() && other.is_array()
//			&& (_right_dim_expr->value()
//			== other._right_dim_expr->value()))
//		{
//			return true;
//		}
//		return false;
//	}
//	return false;
//}


bool FrostFullType::is_same_rhs_type(const FrostFullType& other) const
{
	return ((is_array() == other.is_array())
		&& (right_dim_expr()->value() == other.right_dim_expr()->value()));
}

size_t FrostFullType::right_dim() const
{
	return (_right_dim_expr != nullptr)
		? BigNum(_right_dim_expr->value()).get_ui() : 1;
	//return (_right_dim_expr != nullptr)
	//	? _right_dim_expr->value().convert_to_unsigned_bignum() : 1;
}

} // namespace frost_hdl
