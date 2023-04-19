/**
 * Dang Programming Language Abstract Syntax variable expression component.
 * @author danixdev1205
 */
export module dang.ast.expressions:variable_expression;


import "expression.hxx";


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST variable expression component. */
    class variable_expression final : public expression
    {
    public:
        /**
         * Initializes new AST variable expression.
         * @param identifier Variable identifier.
         */
        explicit variable_expression(const std::wstring& identifier)
            : identifier_(identifier)
        {
        }

    private:
        /** Variable identifier. */
        const std::wstring identifier_;


        /** Outputs variable expression to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << identifier_; }
    };
}
