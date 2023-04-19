/**
 * Dang Programming Language Abstract Syntax variable assignment statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:assignment_statement;


import "statement.hxx";
import dang.ast.expressions;
import dang.enums;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST assignment declaration statement component. */
    class assignment_statement final : public statement
    {
    public:
        /**
         * Initializes new AST print statement.
         * @param expression Assignment AST value expression.
         * @param identifier Assignment identifier.
         * @param _operator Assignment operator.
         */
        explicit assignment_statement(const expression* const expression, const std::wstring& identifier,
                                      const enums::assignment_operator _operator)
            : value_(expression),
              identifier_(identifier),
              operator_(_operator)
        {
        }


        /** AST print statement destructor. */
        ~assignment_statement() override { delete value_; }

    private:
        /** Assignment AST value expression. */
        const expression* const value_;

        /** Assignment identifier. */
        const std::wstring identifier_;

        /** Assignment operator. */
        const enums::assignment_operator operator_;


        /** Outputs variable assignment statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            return os << identifier_ << to_wstring(operator_) << *value_ << ";";
        }
    };
}
