import dang;
import std;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST value component. */
    struct value
    {
        /** AST value destructor. */
        virtual ~value() = default;


        /**
         * Outputs value to a wide character output stream.
         * @param os Wide character output stream.
         * @param obj Abstract syntax tree value component.
         */
        friend std::wostream& operator<<(std::wostream& os, const value& obj) { return obj.out(os); }


#pragma region Conversion

        /** Converts AST value to a Dang Boolean. */
        virtual explicit operator boolean() const = 0;

        /** Converts AST value to a Dang Trilean. */
        virtual explicit operator trilean() const = 0;

        /** Converts AST value to a Dang Integer. */
        virtual explicit operator integer() const = 0;

        /** Converts AST value to a Dang Decimal. */
        virtual explicit operator decimal() const = 0;

        /** Converts AST value to a Dang Symbol. */
        virtual explicit operator symbol() const = 0;

        /** Converts AST value to a Dang String. */
        virtual explicit operator string() const = 0;

        /** Converts AST value to a Dang Array. */
        virtual explicit operator array<value*>() const = 0;

#pragma endregion

    private:
        /** Outputs value to a wide character output stream. */
        [[nodiscard]]
        virtual std::wostream& out(std::wostream&) const = 0;
    };
}
