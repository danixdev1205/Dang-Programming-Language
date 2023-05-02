/**
 * Dang Programming Language Abstract Syntax entry point statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:entry_statement;


import "statement.hxx";


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST entry point statement component. */
    class entry_statement final : public statement
    {
    public:
        /** Initializes new AST entry point statement. */
        explicit entry_statement() = default;

        /**
         * Initializes new AST entry point statement.
         * @param block Block of AST statements.
         */
        explicit entry_statement(const std::vector<const statement*>& block)
            : block_(block)
        {
        }


        /** Executes every statement in the entry. */
        void emplace(const statement* const statement) { block_.emplace_back(statement); }

    private:
        /** Entry of AST statements. */
        std::vector<const statement*> block_;


        /** Outputs entry statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            os << "#include <iostream>\n#include <string>\ntypedef std::string str;template<typename T>T read();template<>int read(){int o;std::cin>>o;return o;}template<>char read(){char o;std::cin>>o;return o;}template<>float read(){float o;std::cin>>o;return o;}template<>str read(){str o;std::cin>>o;return o;}\nint main()\n{\n";
            for (const auto statement : block_)
                os << *statement << '\n';

            return os << "return 0;\n}\n";
        }
    };
}
