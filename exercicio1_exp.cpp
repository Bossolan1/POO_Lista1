#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Autor
{
    private:
        string nome, cpf;
    public:
        Autor(string nome, string cpf) : nome(nome),cpf(cpf) { cout << "autor: '" << nome << "' criado\n"; }
        
        ~Autor(){ cout << "Autor:'" << nome << "' destruido\n"; }
        
        const string getNome() const { return nome; }
}; 

class Livro 
{
    private:
        string titulo, anoDePublicacao;
        Autor* autor;
    public:
        Livro(string titulo, Autor* autor, string anoDePublicacao) : titulo(titulo), autor(autor),anoDePublicacao(anoDePublicacao){
            cout << "Livro('" << titulo << "') criado\n";
        }
        ~Livro() { cout << "Livro('" << titulo << "') destruido\n"; } 
        
        void listarLivro() const
        {
            cout << "\nTitulo: " << titulo;
            cout << "\nAutor: " << autor->getNome();
            cout << "\nAno de publicacao: " << anoDePublicacao;
            cout << "\n";
        }

        const string& getTitulo() const { return titulo; }
};

class Biblioteca {
private:    
    string nome;
    vector<Livro*> livros_cadastrados; // COMPOSIÇÃO
public:
    Biblioteca(const string& n) : nome(n) {cout << "Biblioteca('" << nome << "') criada\n"; }
    ~Biblioteca() { cout << "Biblioteca('" << nome << "') destruida\n"; }

    void adicionarLivro(Livro* livro) { livros_cadastrados.push_back(livro); }
    
    void exibirLivros() const
    {
        cout << "\n----------------------------";
        cout << "\n| Exibidor de livros makrI |";
        cout << "\n----------------------------";
        for (const  auto& livro: livros_cadastrados)
        {
            livro->listarLivro();
        }
        cout << "\n----------------------------\n";
    }
};


int main() {
    {
        Autor autor1("Metaleiro", "123.456.789-00");
        Autor autor2("Padeiro", "987.654.321-00");
        Autor autor3("Carteiro", "111.222.333-44");
        
        Livro livro1("generico1",&autor1, "22-01-1969");
        Livro livro2("generico2",&autor2, "22-01-1970");
        Livro livro3("generico3",&autor3, "22-01-1969");

        Biblioteca biblioteca("Biblioteca California");

        biblioteca.adicionarLivro(&livro1);
        biblioteca.adicionarLivro(&livro2);
        biblioteca.adicionarLivro(&livro3);


        biblioteca.exibirLivros();
    }

    return 1;
}
