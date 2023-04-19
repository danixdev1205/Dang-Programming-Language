/**
 * Dang Programming Language Abstract Syntax binary expression component.
 * @author danixdev1205
 */
export module dang.ast.expressions:binary_expression;


import "expression.hxx";
import dang.ast.values;
import dang.enums;
import std;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST binary expression component. */
    class binary_expression final : public expression
    {
    public:
        /**
         * Initializes new AST binary expression.
         * @param lhs AST left hand side expression.
         * @param rhs AST Right hand side expression.
         * @param _operator Binary expression operator.
         */
        explicit binary_expression(const expression* const lhs, const expression* const rhs,
                                   const enums::binary_operator _operator)
            : lhs_(lhs),
              rhs_(rhs),
              operator_(_operator)
        {
        }


        /** AST binary expression destructor. */
        ~binary_expression() override
        {
            delete lhs_;
            delete rhs_;
        }

    private:
        /** AST left hand side expression. */
        const expression* const lhs_;

        /** AST left hand side expression. */
        const expression* const rhs_;

        /** Binary expression operator. */
        const enums::binary_operator operator_;
        
        /** Outputs binary expression to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << *lhs_ << to_wstring(operator_) << *rhs_; }
    };
}
