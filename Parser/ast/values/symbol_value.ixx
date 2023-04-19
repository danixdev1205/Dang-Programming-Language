/**
 * Dang Programming Language Abstract Syntax Tree Symbol value component.
 * @details @n The named partition @code symbol_value @endcode for the module @code dang.ast.values @endcode
 * exports implementations in namespace @code dang::ast @endcode for AST Symbol value component.
 * @author danixdev1205
 */
export module dang.ast.values:symbol_value;


import "value.hxx";
import dang;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST Symbol value component. */
    struct symbol_value final : value
    {
        /**
         * Initializes new AST Symbol value.
         * @param value Dang Symbol value.
         */
        [[nodiscard]]
        symbol_value(const symbol value)
            : value_(value)
        {
        }

    private:
        /** Dang Symbol value. */
        symbol value_;

        
        /** Outputs value to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "L'" << value_ << '\''; }
    };
}
