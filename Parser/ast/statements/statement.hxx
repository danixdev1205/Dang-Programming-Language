import std;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST statement component. */
    class statement
    {
    public:
        /** AST statement destructor. */
        virtual ~statement() = default;


        /**
         * Outputs value to a wide character output stream.
         * @param os Wide character output stream.
         * @param obj Abstract syntax tree value component.
         */
        friend std::wostream& operator<<(std::wostream& os, const statement& obj) { return obj.out(os); }

    private:
        /** Outputs statement to a wide character output stream. */
        [[nodiscard]]
        virtual std::wostream& out(std::wostream&) const = 0;
    };
}
