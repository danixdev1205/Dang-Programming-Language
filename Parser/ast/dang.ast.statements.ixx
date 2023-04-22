/**
 * Dang Programming Language Abstract Syntax Tree statements components.
 * @author danixdev1205
 */
export module dang.ast.statements;


export import "statements/statement.hxx";

export import :entry_statement;
export import :block_statement;

export import :print_statement;

export import :variable_statement;
export import :constant_statement;
export import :assignment_statement;

export import :if_statement;
export import :else_statement;
