/**
 * Dang Programming Language Abstract Syntax variable declaration statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:variable_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST variable declaration statement component. */
    class variable_statement final : public statement
    {
    public:
        /**
         * Initializes new AST print statement.
         * @param expression Variable AST value expression.
         * @param identifier Variable identifier.
         * @param type Variable data type.
         */
        explicit variable_statement(const expression* const expression, const std::wstring& identifier,
                                    const std::wstring& type = L"auto")
            : value_(expression),
              type_(type),
              identifier_(identifier)
        {
        }


        /** AST print statement destructor. */
        ~variable_statement() override { delete value_; }

    private:
        /** Variable AST value expression. */
        const expression* const value_;

        /** Variable data type. */
        const std::wstring type_;

        /** Variable identifier. */
        const std::wstring identifier_;


        /** Outputs print statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            return os << type_ << " " << identifier_ << "=" << *value_ << ";";
        }
    };
}
