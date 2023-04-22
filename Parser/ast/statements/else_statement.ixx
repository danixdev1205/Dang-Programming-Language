/**
 * Dang Programming Language Abstract Syntax else statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:else_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST else declaration statement component. */
    class else_statement final : public statement
    {
    public:
        /**
         * Initializes new AST else statement.
         * @param body Statement body.
         */
        explicit else_statement(const statement* const body)
            : body_(body)
        {
        }


        /** AST else statement destructor. */
        ~else_statement() override { delete body_; }

    private:
        /** else statement body. */
        const statement* const body_;


        /** Outputs else statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "else " << *body_; }
    };
}
