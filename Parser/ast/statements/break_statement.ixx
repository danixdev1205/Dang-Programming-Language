/**
 * Dang Programming Language Abstract Syntax break statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:break_statement;


import "statement.hxx";


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST break statement component. */
    class break_statement final : public statement
    {
        /** Outputs break statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "break;"; }
    };
}
