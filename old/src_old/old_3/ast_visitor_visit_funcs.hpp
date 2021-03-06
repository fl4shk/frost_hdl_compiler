// src/ast_visitor_visit_funcs.hpp

virtual void visitProgram(NodeProgram* node) = 0;
virtual void visitPackage(NodePackage* node) = 0;
virtual void visitScopePackage(NodeScopePackage* node) = 0;
virtual void visitModule(NodeModule* node) = 0;
virtual void visitScopeModproc(NodeScopeModproc* node) = 0;
virtual void visitParamArgTypeSublist(NodeParamArgTypeSublist* node) = 0;
virtual void visitArgPortSublist(NodeArgPortSublist* node) = 0;
virtual void visitParamArgVarSublist(NodeParamArgVarSublist* node) = 0;
virtual void visitParamModuleSublist(NodeParamModuleSublist* node) = 0;
virtual void visitParamList(NodeParamList* node) = 0;
virtual void visitArgList(NodeArgList* node) = 0;
virtual void visitLeftRightBase(NodeLeftRightBase* node) = 0;
virtual void visitIdentTerminal(NodeIdentTerminal* node) = 0;
virtual void visitIdentMemberAccess(NodeIdentMemberAccess* node) = 0;
virtual void visitIdentScopeAccess(NodeIdentScopeAccess* node) = 0;
virtual void visitCall(NodeCall* node) = 0;
virtual void visitIdentEtc(NodeIdentEtc* node) = 0;
virtual void visitNumExpr(NodeNumExpr* node) = 0;
virtual void visitSizedNumExpr(NodeSizedNumExpr* node) = 0;
virtual void visitBracketPair(NodeBracketPair* node) = 0;
virtual void visitParenPair(NodeParenPair* node) = 0;
virtual void visitHasString(NodeHasString* node) = 0;
virtual void visitIdent(NodeIdent* node) = 0;
virtual void visitConstString(NodeConstString* node) = 0;
virtual void visitScopeBehav(NodeScopeBehav* node) = 0;
virtual void visitEnum(NodeEnum* node) = 0;
virtual void visitScopeEnum(NodeScopeEnum* node) = 0;
virtual void visitClass(NodeClass* node) = 0;
virtual void visitScopeClass(NodeScopeClass* node) = 0;
virtual void visitExtends(NodeExtends* node) = 0;
virtual void visitMemberCallable(NodeMemberCallable* node) = 0;
virtual void visitUnion(NodeUnion* node) = 0;
virtual void visitScopeUnion(NodeScopeUnion* node) = 0;
virtual void visitParamPossibleTypename(NodeParamPossibleTypename* node) = 0;
virtual void visitNoParamPossibleTypename(NodeNoParamPossibleTypename* node) = 0;
virtual void visitTypeof(NodeTypeof* node) = 0;
virtual void visitTypeRange(NodeTypeRange* node) = 0;
virtual void visitRangeSuffix(NodeRangeSuffix* node) = 0;
virtual void visitAuto(NodeAuto* node) = 0;
virtual void visitVoid(NodeVoid* node) = 0;
virtual void visitUwire(NodeUwire* node) = 0;
virtual void visitSwire(NodeSwire* node) = 0;
virtual void visitUbit(NodeUbit* node) = 0;
virtual void visitSbit(NodeSbit* node) = 0;
virtual void visitUbyte(NodeUbyte* node) = 0;
virtual void visitSbyte(NodeSbyte* node) = 0;
virtual void visitUshortint(NodeUshortint* node) = 0;
virtual void visitSshortint(NodeSshortint* node) = 0;
virtual void visitUint(NodeUint* node) = 0;
virtual void visitSint(NodeSint* node) = 0;
virtual void visitUlongint(NodeUlongint* node) = 0;
virtual void visitSlongint(NodeSlongint* node) = 0;
virtual void visitSelf(NodeSelf* node) = 0;
virtual void visitPosParamArgInstList(NodePosParamArgInstList* node) = 0;
virtual void visitNamedParamArgInstList(NodeNamedParamArgInstList* node) = 0;
virtual void visitOneParamArgInst(NodeOneParamArgInst* node) = 0;
virtual void visitExprBase(NodeExprBase* node) = 0;
virtual void visitBinopExprBase(NodeBinopExprBase* node) = 0;
virtual void visitUnopExprBase(NodeUnopExprBase* node) = 0;
virtual void visitBinopExprLogAnd(NodeBinopExprLogAnd* node) = 0;
virtual void visitBinopExprLogOr(NodeBinopExprLogOr* node) = 0;
virtual void visitBinopExprCmpEq(NodeBinopExprCmpEq* node) = 0;
virtual void visitBinopExprCmpNe(NodeBinopExprCmpNe* node) = 0;
virtual void visitBinopExprCmpLt(NodeBinopExprCmpLt* node) = 0;
virtual void visitBinopExprCmpGt(NodeBinopExprCmpGt* node) = 0;
virtual void visitBinopExprCmpLe(NodeBinopExprCmpLe* node) = 0;
virtual void visitBinopExprCmpGe(NodeBinopExprCmpGe* node) = 0;
virtual void visitBinopExprPlus(NodeBinopExprPlus* node) = 0;
virtual void visitBinopExprMinus(NodeBinopExprMinus* node) = 0;
virtual void visitBinopExprMul(NodeBinopExprMul* node) = 0;
virtual void visitBinopExprDiv(NodeBinopExprDiv* node) = 0;
virtual void visitBinopExprMod(NodeBinopExprMod* node) = 0;
virtual void visitBinopExprBitAnd(NodeBinopExprBitAnd* node) = 0;
virtual void visitBinopExprBitOr(NodeBinopExprBitOr* node) = 0;
virtual void visitBinopExprBitXor(NodeBinopExprBitXor* node) = 0;
virtual void visitBinopExprBitLsl(NodeBinopExprBitLsl* node) = 0;
virtual void visitBinopExprBitLsr(NodeBinopExprBitLsr* node) = 0;
virtual void visitBinopExprBitAsr(NodeBinopExprBitAsr* node) = 0;
virtual void visitUnopExprLogNot(NodeUnopExprLogNot* node) = 0;
virtual void visitUnopExprBitNot(NodeUnopExprBitNot* node) = 0;
virtual void visitUnopExprPlus(NodeUnopExprPlus* node) = 0;
virtual void visitUnopExprMinus(NodeUnopExprMinus* node) = 0;
virtual void visitUnopExprDollarUnsigned(NodeUnopExprDollarUnsigned* node) = 0;
virtual void visitUnopExprDollarSigned(NodeUnopExprDollarSigned* node) = 0;
virtual void visitUnopExprDollarIsUnsigned(NodeUnopExprDollarIsUnsigned* node) = 0;
virtual void visitUnopExprDollarIsSigned(NodeUnopExprDollarIsSigned* node) = 0;
virtual void visitUnopExprDollarRange(NodeUnopExprDollarRange* node) = 0;
virtual void visitUnopExprDollarRevrange(NodeUnopExprDollarRevrange* node) = 0;
virtual void visitUnopExprDollarSize(NodeUnopExprDollarSize* node) = 0;
virtual void visitUnopExprDollarFirst(NodeUnopExprDollarFirst* node) = 0;
virtual void visitUnopExprDollarLast(NodeUnopExprDollarLast* node) = 0;
virtual void visitUnopExprDollarHigh(NodeUnopExprDollarHigh* node) = 0;
virtual void visitUnopExprDollarLow(NodeUnopExprDollarLow* node) = 0;
virtual void visitUnopExprDollarClog2(NodeUnopExprDollarClog2* node) = 0;
virtual void visitBinopExprDollarPow(NodeBinopExprDollarPow* node) = 0;
virtual void visitPseudoExprDollarBase(NodePseudoExprDollarBase* node) = 0;
virtual void visitPseudoExprDollarPast(NodePseudoExprDollarPast* node) = 0;
virtual void visitPseudoExprDollarStable(NodePseudoExprDollarStable* node) = 0;
virtual void visitPseudoExprDollarRose(NodePseudoExprDollarRose* node) = 0;
virtual void visitPseudoExprDollarFell(NodePseudoExprDollarFell* node) = 0;
virtual void visitPseudoExprDollarGlobalClock(NodePseudoExprDollarGlobalClock* node) = 0;
virtual void visitUnopExprTypeof(NodeUnopExprTypeof* node) = 0;
virtual void visitCatExpr(NodeCatExpr* node) = 0;
virtual void visitListCat(NodeListCat* node) = 0;
virtual void visitReplExpr(NodeReplExpr* node) = 0;
virtual void visitRangeExprAny(NodeRangeExprAny* node) = 0;
virtual void visitRangeOne(NodeRangeOne* node) = 0;
virtual void visitRangeTwo(NodeRangeTwo* node) = 0;
virtual void visitStmtList(NodeStmtList* node) = 0;
virtual void visitAnyForStmt(NodeAnyForStmt* node) = 0;
virtual void visitForStmt(NodeForStmt* node) = 0;
virtual void visitGenerateForStmt(NodeGenerateForStmt* node) = 0;
virtual void visitIfStmt(NodeIfStmt* node) = 0;
virtual void visitGenerateIfStmt(NodeGenerateIfStmt* node) = 0;
virtual void visitWhileStmt(NodeWhileStmt* node) = 0;
virtual void visitBehavAssignStmt(NodeBehavAssignStmt* node) = 0;
virtual void visitContAssignStmt(NodeContAssignStmt* node) = 0;
virtual void visitMemberAccessPublicStmt(NodeMemberAccessPublicStmt* node) = 0;
virtual void visitMemberAccessProtectedStmt(NodeMemberAccessProtectedStmt* node) = 0;
virtual void visitMemberAccessPrivateStmt(NodeMemberAccessPrivateStmt* node) = 0;
virtual void visitSwitchStmt(NodeSwitchStmt* node) = 0;
virtual void visitSwitchzStmt(NodeSwitchzStmt* node) = 0;
virtual void visitExprCaseItem(NodeExprCaseItem* node) = 0;
virtual void visitDefaultCaseItem(NodeDefaultCaseItem* node) = 0;
virtual void visitScopeSwitch(NodeScopeSwitch* node) = 0;
virtual void visitUsingStmt(NodeUsingStmt* node) = 0;
virtual void visitInstModuleStmt(NodeInstModuleStmt* node) = 0;
virtual void visitReturnStmt(NodeReturnStmt* node) = 0;
virtual void visitDollarResizeStmt(NodeDollarResizeStmt* node) = 0;
virtual void visitInitialBlock(NodeInitialBlock* node) = 0;
virtual void visitAlwaysCombBlock(NodeAlwaysCombBlock* node) = 0;
virtual void visitAlwaysBlkBlock(NodeAlwaysBlkBlock* node) = 0;
virtual void visitAlwaysFfBlock(NodeAlwaysFfBlock* node) = 0;
virtual void visitAssertStmt(NodeAssertStmt* node) = 0;
virtual void visitAssumeStmt(NodeAssumeStmt* node) = 0;
virtual void visitCoverStmt(NodeCoverStmt* node) = 0;
virtual void visitRestrictStmt(NodeRestrictStmt* node) = 0;
virtual void visitStaticAssertStmt(NodeStaticAssertStmt* node) = 0;
virtual void visitPosedgeInst(NodePosedgeInst* node) = 0;
virtual void visitNegedgeInst(NodeNegedgeInst* node) = 0;
virtual void visitEdgeList(NodeEdgeList* node) = 0;
virtual void visitDeclCallable(NodeDeclCallable* node) = 0;
virtual void visitDeclFunc(NodeDeclFunc* node) = 0;
virtual void visitDeclProc(NodeDeclProc* node) = 0;
virtual void visitDeclTask(NodeDeclTask* node) = 0;
virtual void visitIdentTermEqualsExtra(NodeIdentTermEqualsExtra* node) = 0;
virtual void visitIdentTermEqualsExtraList(NodeIdentTermEqualsExtraList* node) = 0;
virtual void visitDeclConstList(NodeDeclConstList* node) = 0;
virtual void visitDeclVarList(NodeDeclVarList* node) = 0;
virtual void visitModport(NodeModport* node) = 0;
virtual void visitModportSubList(NodeModportSubList* node) = 0;
virtual void visitIdentList(NodeIdentList* node) = 0;
