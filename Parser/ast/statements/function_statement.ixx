export module dang.ast.statements:function_statement;


import "statement.hxx";
import dang.ast.expressions;
import std;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST function expression component. */
    class function_statement final : public statement
    {
    public:
        /**
         * Initializes new AST function expression.
         * @param identifier function identifier.
         */
        explicit function_statement(const std::wstring& identifier)
            : identifier_(identifier)
        {
        }

        explicit function_statement(const std::wstring& identifier, std::vector<const expression*> parameters)
            : identifier_(identifier),
              parameters_(parameters)
        {
        }

    private:
        /** function identifier. */
        const std::wstring identifier_;
        
        std::vector<const expression*> parameters_;


        /** Outputs function expression to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            os << identifier_ << "(";

            for (auto i = 0; i < parameters_.size(); i++)
            {
                os << *parameters_[i];

                if (i != parameters_.size() - 1)
                    os << ",";
            }
            
            return os << ");";
        }
    };
}
