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


#pragma region Conversion

        /** Converts AST Symbol value to a Dang Boolean. */
        explicit operator boolean() const override { throw; }

        /** Converts AST Symbol value to a Dang Trilean. */
        explicit operator trilean() const override { throw; }

        /** Converts AST Symbol value to a Dang Integer. */
        explicit operator integer() const override { throw; }

        /** Converts AST Symbol value to a Dang Decimal. */
        explicit operator decimal() const override { throw; }

        /** Reads AST Symbol value as a Dang Symbol. */
        explicit operator symbol() const override { return value_; }

        /** Converts AST Symbol value to a Dang String. */
        explicit operator string() const override { return string() + value_; }

        /** Converts AST Symbol value to a Dang Array. */
        explicit operator array<value*>() const override { throw; }

#pragma endregion

    private:
        /** Dang Symbol value. */
        symbol value_;

        
        /** Outputs value to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "L'" << value_ << '\''; }
    };
}
