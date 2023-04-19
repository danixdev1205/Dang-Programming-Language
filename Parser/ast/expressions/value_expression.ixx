/**
 * Dang Programming Language Abstract Syntax value expression component.
 * @author danixdev1205
 */
export module dang.ast.expressions:value_expression;


import "expression.hxx";


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST value expression component. */
    class value_expression final : public expression
    {
    public:
        /**
         * Initializes new AST value expression.
         * @param value AST value.
         */
        explicit value_expression(const value* const value)
            : value_(value)
        {
        }


        /** AST value expression destructor. */
        ~value_expression() override { delete value_; }

    private:
        /** AST value. */
        const value* const value_;


        /** Outputs value expression to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << *value_; }
    };
}
