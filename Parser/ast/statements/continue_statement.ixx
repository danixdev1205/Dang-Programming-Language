/**
 * Dang Programming Language Abstract Syntax continue statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:continue_statement;


import "statement.hxx";


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST continue statement component. */
    class continue_statement final : public statement
    {
        /** Outputs continue statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "continue;"; }
    };
}
