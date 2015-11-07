/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_ORFZ_SRC_GEN_FLATZINC_PARSER_TAB_HH_INCLUDED
# define YY_ORFZ_SRC_GEN_FLATZINC_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int orfz_debug;
#endif
/* "%code requires" blocks.  */
#line 20 "src/flatzinc/parser.yy" /* yacc.c:1909  */

#if !defined(OR_TOOLS_FLATZINC_FLATZINC_TAB_HH_)
#define OR_TOOLS_FLATZINC_FLATZINC_TAB_HH_
#include "base/map_util.h"
#include "base/strutil.h"
#include "flatzinc/model.h"

namespace operations_research {
// This is the context used during parsing.
struct FzParserContext {
  hash_map<std::string, int64> integer_map;
  hash_map<std::string, std::vector<int64> > integer_array_map;
  hash_map<std::string, FzIntegerVariable*> variable_map;
  hash_map<std::string, std::vector<FzIntegerVariable*> > variable_array_map;
  hash_map<std::string, FzDomain> domain_map;
  hash_map<std::string, std::vector<FzDomain> > domain_array_map;
};

// An optional reference to a variable, or an integer value, used in
// assignments during the declaration of a variable, or a variable
// array.
struct VariableRefOrValue {
  static VariableRefOrValue Undefined() {
    VariableRefOrValue result;
    result.variable = nullptr;
    result.value = 0;
    result.defined = false;
    return result;
  }
  static VariableRefOrValue VariableRef(FzIntegerVariable* var) {
    VariableRefOrValue result;
    result.variable = var;
    result.value = 0;
    result.defined = true;
    return result;
  }
  static VariableRefOrValue Value(int64 value) {
    VariableRefOrValue result;
    result.variable = nullptr;
    result.value = value;
    result.defined = true;
    return result;
  }

  FzIntegerVariable* variable;
  int64 value;
  bool defined;
};

struct VariableRefOrValueArray {
  std::vector<FzIntegerVariable*> variables;
  std::vector<int64> values;

  void PushBack(const VariableRefOrValue& v) {
    CHECK(v.defined);
    variables.push_back(v.variable);
    values.push_back(v.value);
  }

  int Size() const {
    return values.size();
  }
};

// Class needed to pass information from the lexer to the parser.
// TODO(lperron): Use std::unique_ptr<std::vector< >> to ease memory management.
struct LexerInfo {
  int64 integer_value;
  double double_value;
  std::string string_value;
  FzDomain domain;
  std::vector<FzDomain>* domains;
  std::vector<int64>* integers;
  FzArgument arg;
  std::vector<FzArgument>* args;
  FzAnnotation annotation;
  std::vector<FzAnnotation>* annotations;
  VariableRefOrValue var_or_value;
  VariableRefOrValueArray* var_or_value_array;
};
}  // namespace operations_research

// Tells flex to use the LexerInfo class to communicate with the bison parser.
typedef operations_research::LexerInfo YYSTYPE;

// Defines the parameter to the orfz_lex() call from the orfz_parse() method.
#define YYLEX_PARAM scanner

#endif  // OR_TOOLS_FLATZINC_FLATZINC_TAB_HH_

#line 135 "src\\\\gen/flatzinc/parser.tab.hh" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    BOOL = 259,
    CONSTRAINT = 260,
    FLOAT = 261,
    INT = 262,
    MAXIMIZE = 263,
    MINIMIZE = 264,
    OF = 265,
    PREDICATE = 266,
    SATISFY = 267,
    SET = 268,
    SOLVE = 269,
    VAR = 270,
    DOTDOT = 271,
    COLONCOLON = 272,
    IVALUE = 273,
    SVALUE = 274,
    IDENTIFIER = 275,
    DVALUE = 276
  };
#endif

/* Value type.  */



int orfz_parse (operations_research::FzParserContext* context, operations_research::FzModel* model, bool* ok, void* scanner);

#endif /* !YY_ORFZ_SRC_GEN_FLATZINC_PARSER_TAB_HH_INCLUDED  */
