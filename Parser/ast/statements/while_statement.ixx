/**
 * Dang Programming Language Abstract Syntax while statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:while_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST while declaration statement component. */
    class while_statement final : public statement
    {
    public:
        /**
         * Initializes new AST while statement.
         * @param condition Statement condition.
         * @param body Statement body.
         */
        explicit while_statement(const expression* const condition, const statement* const body)
            : condition_(condition),
              body_(body)
        {
        }


        /** AST while statement destructor. */
        ~while_statement() override
        {
            delete condition_;
            delete body_;
        }

    private:
        /** While statement condition expression. */
        const expression* const condition_;

        /** While statement body. */
        const statement* const body_;


        /** Outputs while statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            return os << "while(" << *condition_ << ")" << *body_;
        }
    };
}
