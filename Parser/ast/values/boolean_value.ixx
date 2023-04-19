/**
 * Dang Programming Language Abstract Syntax Tree Boolean value component.
 * @details @n The named partition @code boolean_value @endcode for the module @code dang.ast.values @endcode
 * exports implementations in namespace @code dang::ast @endcode for AST Boolean value component.
 * @author danixdev1205
 */
export module dang.ast.values:boolean_value;


import "value.hxx";
import dang;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST Boolean value component. */
    struct boolean_value final : value
    {
        /**
         * Initializes new AST Boolean value.
         * @param value Dang Boolean value.
         */
        [[nodiscard]]
        boolean_value(const boolean value)
            : value_(value)
        {
        }


#pragma region Conversion

        /** Reads AST Boolean value as a Dang Boolean. */
        explicit operator boolean() const override { return value_; }

        /** Converts AST Boolean value to a Dang Trilean. */
        explicit operator trilean() const override { return value_; }

        /** Converts AST Boolean value to a Dang Integer. */
        explicit operator integer() const override { throw; }

        /** Converts AST Boolean value to a Dang Decimal. */
        explicit operator decimal() const override { throw; }

        /** Converts AST Boolean value to a Dang Symbol. */
        explicit operator symbol() const override { throw; }

        /** Converts AST Boolean value to a Dang String. */
        explicit operator string() const override { throw; }

        /** Converts AST Boolean value to a Dang Array. */
        explicit operator array<value*>() const override { throw; }

#pragma endregion

    private:
        /** Dang Boolean value. */
        boolean value_;

        
        /** Outputs value to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << (value_ ? "true" : "false"); }
    };
}
