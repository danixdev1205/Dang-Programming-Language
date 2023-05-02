/**
 * Dang Programming Language Abstract Syntax Tree String value component.
 * @details @n The named partition @code string_value @endcode for the module @code dang.ast.values @endcode
 * exports implementations in namespace @code dang::ast @endcode for AST String value component.
 * @author danixdev1205
 */
export module dang.ast.values:string_value;


import "value.hxx";
import dang;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST String value component. */
    struct string_value final : value
    {
        /**
         * Initializes new AST String value.
         * @param value Dang String value.
         */
        [[nodiscard]]
        string_value(const string& value)
            : value_(value)
        {
        }

    private:
        /** Dang String value. */
        string value_;

        
        /** Outputs value to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "\"" << value_ << '"'; }
    };
}
