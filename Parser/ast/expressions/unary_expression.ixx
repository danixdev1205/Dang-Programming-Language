/**
 * Dang Programming Language Abstract Syntax unary expression component.
 * @author danixdev1205
 */
export module dang.ast.expressions:unary_expression;


import "expression.hxx";
import dang.enums;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST unary expression component. */
    class unary_expression final : public expression
    {
    public:
        /**
         * Initializes new AST unary expression.
         * @param expression AST expression.
         * @param _operator Unary expression operator.
         */
        explicit unary_expression(const expression* const expression, const enums::unary_operator _operator)
            : expression_(expression),
              operator_(_operator)
        {
        }


        /** AST unary expression destructor. */
        ~unary_expression() override { delete expression_; }

    private:
        /** AST expression. */
        const expression* const expression_;

        /** Unary expression operator. */
        const enums::unary_operator operator_;


        /** Outputs unary expression to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            return os << '(' << to_wstring(operator_) << *expression_ << ')';
        }
    };
}
