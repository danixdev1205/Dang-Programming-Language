/**
 * Dang Programming Language Abstract Syntax if statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:if_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST if declaration statement component. */
    class if_statement final : public statement
    {
    public:
        /**
         * Initializes new AST print statement.
         * @param condition Statement condition.
         * @param body Statement body.
         */
        explicit if_statement(const expression* const condition, const statement* const body)
            : condition_(condition),
              body_(body)
        {
        }


        /** AST if statement destructor. */
        ~if_statement() override
        {
            delete condition_;
            delete body_;
        }

    private:
        /** If statement condition expression. */
        const expression* const condition_;

        /** If statement body. */
        const statement* const body_;


        /** Outputs if statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            return os << "if(" << *condition_ << ")" << *body_;
        }
    };
}
