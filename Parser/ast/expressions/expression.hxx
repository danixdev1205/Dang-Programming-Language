import dang.ast.values;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST expression component. */
    class expression
    {
    public:
        /** AST expression destructor. */
        virtual ~expression() = default;


        /**
         * Outputs value to a wide character output stream.
         * @param os Wide character output stream.
         * @param obj Abstract syntax tree value component.
         */
        friend std::wostream& operator<<(std::wostream& os, const expression& obj) { return obj.out(os); }

    private:
        /** Outputs expression to a wide character output stream. */
        [[nodiscard]]
        virtual std::wostream& out(std::wostream&) const = 0;
    };
}
