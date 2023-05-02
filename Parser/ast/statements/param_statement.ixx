/**
 * Dang Programming Language Abstract Syntax param declaration statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:param_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST param declaration statement component. */
    class param_statement final : public statement
    {
    public:
        /**
         * Initializes new AST print statement.
         * @param expression param AST value expression.
         * @param identifier param identifier.
         * @param type param data type.
         */
        explicit param_statement(const std::wstring& identifier,
                                    const std::wstring& type = L"auto")
            : type_(type),
              identifier_(identifier)
        {
        }

    private:
        /** param data type. */
        const std::wstring type_;

        /** param identifier. */
        const std::wstring identifier_;


        /** Outputs print statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            return os << type_ << " " << identifier_;
        }
    };
}
