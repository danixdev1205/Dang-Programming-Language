/**
 * Dang Programming Language Abstract Syntax Tree Decimal value component.
 * @details @n The named partition @code decimal_value @endcode for the module @code dang.ast.values @endcode
 * exports implementations in namespace @code dang::ast @endcode for AST Decimal value component.
 * @author danixdev1205
 */
export module dang.ast.values:decimal_value;


import "value.hxx";
import dang;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST Decimal value component. */
    struct decimal_value final : value
    {
        /**
         * Initializes new AST Decimal value.
         * @param value Dang Decimal value.
         */
        [[nodiscard]]
        decimal_value(const decimal value)
            : value_(value)
        {
        }
    
    private:
        /** Dang Decimal value. */
        decimal value_;

        
        /** Outputs value to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << value_; }
    };
}
