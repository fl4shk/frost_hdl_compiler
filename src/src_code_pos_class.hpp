#ifndef src_src_code_pos_class_hpp
#define src_src_code_pos_class_hpp

// src/src_code_pos_class.hpp

#include "misc_includes.hpp"
#include <ANTLRErrorListener.h>

namespace frost_hdl
{

// Used for error reporting during semantic analysis.
// Many, many things use this.
class SrcCodePos
{
private:		// variables
	antlr4::ParserRuleContext* _ctx = nullptr;
	size_t _src_line = 0, _src_pos_in_line = 0;

public:		// functions
	SrcCodePos();
	explicit SrcCodePos(antlr4::ParserRuleContext* s_ctx);

	//GEN_MOVE_ONLY_CONSTRUCTORS_AND_ASSIGN(SrcCodePos);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(SrcCodePos);

	virtual ~SrcCodePos();

	std::string convert_to_errwarn_string() const;

	inline void err(const std::string& msg) const
	{
		printerr("Error on ", convert_to_errwarn_string(), ":  ", msg,
			"\n");
		exit(1);
	}
	inline void warn(const std::string& msg) const
	{
		printerr("Warning on ", convert_to_errwarn_string(), ":  ", msg,
			"\n");
	}


	GEN_GETTER_BY_VAL(ctx)
	GEN_GETTER_BY_VAL(src_line)
	GEN_GETTER_BY_VAL(src_pos_in_line)
};

} // namespace frost_hdl


#endif		// src_src_code_pos_class_hpp