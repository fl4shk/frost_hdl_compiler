// src/ast_node_type_enum.hpp

enum class Type
{
	Base,
	List,
	Program,
	Package,
	ScopePackage,
	Module,
	ScopeModproc,
	ParamArgTypeSublist,
	ArgPortSublist,
	ParamArgVarSublist,
	ParamModuleSublist,
	ParamList,
	ArgList,
	LeftRightBase,
	IdentTerminal,
	IdentMemberAccess,
	IdentScopeAccess,
	Call,
	IdentEtc,
	NumExpr,
	SizedNumExpr,
	BracketPair,
	ParenPair,
	HasString,
	Ident,
	ConstString,
	ScopeBehav,
	Enum,
	ScopeEnum,
	Class,
	ScopeClass,
	Extends,
	MemberCallable,
	Union,
	ScopeUnion,
	ParamPossibleTypename,
	NoParamPossibleTypename,
	Typeof,
	TypeRange,
	Auto,
	Void,
	Uwire,
	Swire,
	Ubit,
	Sbit,
	Ubyte,
	Sbyte,
	Ushortint,
	Sshortint,
	Uint,
	Sint,
	Ulongint,
	Slongint,
	Self,
	PosParamArgInstList,
	NamedParamArgInstList,
	OneParamArgInst,
	ExprBase,
	ExprBinopBase,
	ExprUnopBase,
	ExprBinopLogAnd,
	ExprBinopLogOr,
	ExprBinopCmpEq,
	ExprBinopCmpNe,
	ExprBinopCmpLt,
	ExprBinopCmpGt,
	ExprBinopCmpLe,
	ExprBinopCmpGe,
	ExprBinopPlus,
	ExprBinopMinus,
	ExprBinopMul,
	ExprBinopDiv,
	ExprBinopMod,
	ExprBinopBitAnd,
	ExprBinopBitOr,
	ExprBinopBitXor,
	ExprBinopBitLsl,
	ExprBinopBitLsr,
	ExprBinopBitAsr,
	ExprUnopLogNot,
	ExprUnopBitNot,
	ExprUnopPlus,
	ExprUnopMinus,
	ExprUnopDollarUnsgn,
	ExprUnopDollarSgn,
	ExprUnopDollarIsUnsgn,
	ExprUnopDollarIsSgn,
	ExprUnopDollarRange,
	ExprUnopDollarSize,
	ExprUnopDollarFirst,
	ExprUnopDollarLast,
	ExprUnopDollarHigh,
	ExprUnopDollarLow,
	ExprUnopDollarClog2,
	ExprBinopDollarPow,
	PseudoExprDollarBase,
	PseudoExprDollarPast,
	PseudoExprDollarStable,
	PseudoExprDollarRose,
	PseudoExprDollarFell,
	PseudoExprDollarGlobalClock,
	ExprUnopTypeof,
	ExprCat,
	ListCat,
	ExprRepl,
	ExprRangeAny,
	RangeOne,
	RangeTwo,
	StmtList,
	StmtAnyFor,
	StmtFor,
	StmtGenerateFor,
	StmtIf,
	StmtGenerateIf,
	StmtWhile,
	StmtBehavAssign,
	StmtContAssign,
	StmtMemberAccessPublic,
	StmtMemberAccessProtected,
	StmtMemberAccessPrivate,
	StmtSwitch,
	StmtSwitchz,
	StmtCase,
	StmtDefault,
	ScopeSwitch,
	StmtUsing,
	StmtInstModule,
	StmtReturn,
	StmtInitial,
	StmtAlwaysComb,
	StmtAlwaysBlk,
	StmtAlwaysFf,
	StmtAssert,
	StmtAssume,
	StmtCover,
	StmtRestrict,
	StmtStaticAssert,
	PosedgeInst,
	NegedgeInst,
	EdgeList,
	DeclCallable,
	DeclFunc,
	DeclProc,
	DeclTask,
	IdentTermEqualsExtra,
	IdentTermEqualsExtraList,
	DeclConstList,
	DeclVarList,
};
