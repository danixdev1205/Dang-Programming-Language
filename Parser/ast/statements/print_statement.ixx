/**
 * Dang Programming Language Abstract Syntax print statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:print_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST print statement component. */
    class print_statement final : public statement
    {
    public:
        /**
         * Initializes new AST print statement.
         * @param expression AST expression.
         */
        explicit print_statement(const expression* const expression)
            : expression_(expression)
        {
        }


        /** AST print statement destructor. */
        ~print_statement() override { delete expression_; }

    private:
        /** AST expression. */
        const expression* const expression_;


        /** Outputs print statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "std::cout<<" << *expression_ << ";"; }
    };
}
