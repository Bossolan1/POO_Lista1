#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Cliente
{
    private:
        string nome, cpf, endereco;
    public:
        Cliente(string nome, string cpf,string endereco) : nome(nome),cpf(cpf), endereco(endereco) { cout << "Cliente: '" << nome << "' criado\n"; }

        ~Cliente(){ cout << "Cliente:'" << nome << "' destruido\n"; }

        const string getNome() const { return nome; }
        const string getEndereco() const { return endereco; }
};

class Produto
{
    private:
        string produto, quantidade ,diaDeVenda;
        Cliente* cliente;
    public:
        Produto(string produto, string quantidade, Cliente* cliente, string diaDeVenda) : produto(produto), quantidade(quantidade) ,cliente(cliente), diaDeVenda(diaDeVenda){
            cout << "Produto('" << produto << "') criado\n";
        }
        ~Produto() { cout << "Produto: " << produto << "') destruido\n"; }

        void listarProduto() const
        {
            cout << "\nProduto: " << produto;
            cout << "\nQuantidade: " << quantidade;
            cout << "\nCliente: " << cliente->getNome();
            cout << "\nEndereco: " << cliente->getEndereco();
            cout << "\ndia da venda: " << diaDeVenda;
            cout << "\n";
        }

        const string& getTitulo() const { return produto; }
};

class Venda {
private:
    string cod_venda;
    vector<Produto*> vendas_cadastradas; // COMPOSIÇÃO
public:
    Venda(const string& n) : cod_venda(n) {cout << "Venda cod:('" << cod_venda << "') criada\n"; }
    ~Venda() { cout << "cod venda: ('" << cod_venda << "') destruida\n"; }

    void adicionarVenda(Produto* produto) { vendas_cadastradas.push_back(produto); }

    void exibirVendas() const
    {
        cout << "\n-----------------------------";
        cout << "\n| Exibidor de vendas makrI |";
        cout << "\n-----------------------------";
        for (const  auto& produto: vendas_cadastradas)
        {
            produto->listarProduto();
        }
        cout << "\n----------------------------\n";
    }
};


int main() {
    {
        Cliente cliente1("Sewerslvt", "123.456.789-00","blablabla");
        Cliente cliente2("prettycvnt", "987.654.321-00","blablabla");
        Cliente cliente3("Fasto", "111.222.333-44","blablabla");

        Produto produto1("Mr Kill myserlf","1", &cliente1, "22-01-2018");
        Produto produto2("Monster","2",&cliente2, "22-01-2013");
        Produto produto3("Rush E","2.2",&cliente3, "22-01-2015");

        Venda venda("Venda California");

        venda.adicionarVenda(&produto1);
        venda.adicionarVenda(&produto2);
        venda.adicionarVenda(&produto3);


        venda.exibirVendas();
    }

    return 3;
}
