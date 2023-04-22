/**
 * Dang Programming Language Abstract Syntax do statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:do_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST do declaration statement component. */
    class do_statement final : public statement
    {
    public:
        /**
         * Initializes new AST do statement.
         * @param condition Statement condition.
         * @param body Statement body.
         */
        explicit do_statement(const expression* const condition, const statement* const body)
            : condition_(condition),
              body_(body)
        {
        }


        /** AST do statement destructor. */
        ~do_statement() override
        {
            delete condition_;
            delete body_;
        }

    private:
        /** Do statement condition expression. */
        const expression* const condition_;

        /** Do statement body. */
        const statement* const body_;


        /** Outputs do statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            return os << "do " << *body_ << "while(" << *condition_ << ");";
        }
    };
}
