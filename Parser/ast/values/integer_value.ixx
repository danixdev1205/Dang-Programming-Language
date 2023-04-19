/**
 * Dang Programming Language Abstract Syntax Tree Integer value component.
 * @details @n The named partition @code integer_value @endcode for the module @code dang.ast.values @endcode
 * exports implementations in namespace @code dang::ast @endcode for AST Integer value component.
 * @author danixdev1205
 */
export module dang.ast.values:integer_value;


import "value.hxx";
import dang;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST Integer value component. */
    struct integer_value final : value
    {
        /**
         * Initializes new AST Integer value.
         * @param value Dang Integer value.
         */
        [[nodiscard]]
        integer_value(const integer value)
            : value_(value)
        {
        }

    private:
        /** Dang Integer value. */
        integer value_;

        
        /** Outputs value to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << value_; }
    };
}
