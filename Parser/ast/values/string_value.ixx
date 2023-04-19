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


#pragma region Conversion

        /** Converts AST String value to a Dang Boolean. */
        explicit operator boolean() const override { throw; }

        /** Converts AST String value to a Dang Trilean. */
        explicit operator trilean() const override { throw; }

        /** Converts AST String value to a Dang Integer. */
        explicit operator integer() const override { throw; }

        /** Converts AST String value to a Dang Decimal. */
        explicit operator decimal() const override { throw; }

        /** Converts AST String value to a Dang Symbol. */
        explicit operator symbol() const override { return value_[0]; }

        /** Reads AST String value as a Dang String. */
        explicit operator string() const override { return value_; }

        /** Converts AST String value to a Dang Array. */
        explicit operator array<value*>() const override { throw; }

#pragma endregion

    private:
        /** Dang String value. */
        string value_;

        
        /** Outputs value to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "L\"" << value_ << '"'; }
    };
}
