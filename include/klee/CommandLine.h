/*
 * This header groups command line options declarations and associated data
 * that is common for klee and kleaver.
 */

#ifndef KLEE_COMMANDLINE_H
#define KLEE_COMMANDLINE_H

#include "llvm/Support/CommandLine.h"
#include "klee/Config/config.h"

namespace klee {

extern llvm::cl::opt<bool> UseFastCexSolver;

extern llvm::cl::opt<bool> UseCexCache;

extern llvm::cl::opt<bool> UseCache;

extern llvm::cl::opt<bool> UseIndependentSolver; 

extern llvm::cl::opt<bool> DebugValidateSolver;
  
extern llvm::cl::opt<int> MinQueryTimeToLog;

extern llvm::cl::opt<double> MaxCoreSolverTime;

extern llvm::cl::opt<bool> UseForkedCoreSolver;

extern llvm::cl::opt<bool> CoreSolverOptimizeDivides;

extern llvm::cl::opt<bool> UseAssignmentValidatingSolver;

///The different query logging solvers that can switched on/off
enum QueryLoggingSolverType
{
    ALL_KQUERY,   ///< Log all queries (un-optimised) in .kquery (KQuery) format
    ALL_SMTLIB,   ///< Log all queries (un-optimised)  .smt2 (SMT-LIBv2) format
    SOLVER_KQUERY,///< Log queries passed to solver (optimised) in .kquery (KQuery) format
    SOLVER_SMTLIB ///< Log queries passed to solver (optimised) in .smt2 (SMT-LIBv2) format
};

extern llvm::cl::bits<QueryLoggingSolverType> queryLoggingOptions;

enum CoreSolverType {
  STP_SOLVER,
  METASMT_SOLVER,
  DUMMY_SOLVER,
  Z3_SOLVER,
  NO_SOLVER
};
extern llvm::cl::opt<CoreSolverType> CoreSolverToUse;

extern llvm::cl::opt<CoreSolverType> DebugCrossCheckCoreSolverWith;

#ifdef ENABLE_METASMT

enum MetaSMTBackendType
{
    METASMT_BACKEND_STP,
    METASMT_BACKEND_Z3,
    METASMT_BACKEND_BOOLECTOR
};

extern llvm::cl::opt<klee::MetaSMTBackendType> MetaSMTBackend;

#endif /* ENABLE_METASMT */

}

#endif	/* KLEE_COMMANDLINE_H */

