/**
 * Dang Programming Language Abstract Syntax println statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:println_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST println statement component. */
    class println_statement final : public statement
    {
    public:
        /**
         * Initializes new AST println statement.
         * @param expression AST expression.
         */
        explicit println_statement(const expression* const expression)
            : expression_(expression)
        {
        }


        /** AST println statement destructor. */
        ~println_statement() override { delete expression_; }

    private:
        /** AST expression. */
        const expression* const expression_;


        /** Outputs println statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "std::cout<<" << *expression_ << "<<std::endl;"; }
    };
}
