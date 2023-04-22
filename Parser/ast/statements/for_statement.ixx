/**
 * Dang Programming Language Abstract Syntax for statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:for_statement;


import "statement.hxx";
import dang.ast.expressions;
import std;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST for declaration statement component. */
    class for_statement final : public statement
    {
    public:
        /**
         * Initializes new AST for statement.
         * @param initialization Init.
         * @param condition Cond.
         * @param modification Mod.
         * @param body Statement body.
         */
        explicit for_statement(const statement* const initialization, const expression* const condition,
                               const statement* const modification, const statement* const body)
            : initialization_(initialization),
              condition_(condition),
              modification_(modification),
              body_(body)
        {
        }


        /** AST for statement destructor. */
        ~for_statement() override
        {
            delete initialization_;
            delete condition_;
            delete modification_;
            delete body_;
        }

    private:
        /** For statement initialization statement. */
        const statement* const initialization_;

        /** For statement condition expression. */
        const expression* const condition_;

        /** For statement modification statement. */
        const statement* const modification_;

        /** For statement body. */
        const statement* const body_;


        /** Outputs for statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            std::wstringstream ss;
            ss << "for(" << *initialization_ << *condition_ << ";" << *modification_;

            auto s = ss.str();
            s.pop_back();
            
            return os << s << ")" << *body_;
        }
    };
}
