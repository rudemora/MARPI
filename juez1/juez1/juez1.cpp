// juez1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <memory>
#include <cassert>
#include <fstream>

using namespace std;

template <class T> class BinTree {
public:
    BinTree() : root_node(nullptr) {}

    BinTree(const T& elem)
        : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}

    BinTree(const BinTree& left, const T& elem, const BinTree& right)
        : root_node(std::make_shared<TreeNode>(left.root_node, elem,
            right.root_node)) {}

    bool empty() const { return root_node == nullptr; }

    const T& root() const {
        assert(root_node != nullptr);
        return root_node->elem;
    }

    BinTree left() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->left;
        return result;
    }

    BinTree right() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->right;
        return result;
    }

    void display(std::ostream& out) const { display_node(root_node, out); }
private:
    // Las definiciones de TreeNode y NodePointer dependen recursivamente
    // la una de la otra. Por eso declaro 'struct TreeNode;' antes de NodePointer
    // para que el compilador sepa, cuando analice la definición de NodePointer,
    // que TreeNode va a ser definida más adelante.

    struct TreeNode;
    using NodePointer = std::shared_ptr<TreeNode>;

    struct TreeNode {
        TreeNode(const NodePointer& left, const T& elem, const NodePointer& right)
            : elem(elem), left(left), right(right) {}

        T elem;
        NodePointer left, right;
    };

    NodePointer root_node;

    static void display_node(const NodePointer& root, std::ostream& out) {
        if (root == nullptr) {
            out << ".";
        }
        else {
            out << "(";
            display_node(root->left, out);
            out << " " << root->elem << " ";
            display_node(root->right, out);
            out << ")";
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const BinTree<T>& tree) {
    tree.display(out);
    return out;
}

template <typename T> BinTree<T> read_tree(std::istream& in) {
    char c;
    in >> c;
    if (c == '.') {
        return BinTree<T>();
    }
    else {
        assert(c == '(');
        BinTree<T> left = read_tree<T>(in);
        T elem;
        in >> elem;
        BinTree<T> right = read_tree<T>(in);
        in >> c;
        assert(c == ')');
        BinTree<T> result(left, elem, right);
        return result;
    }
}



/*@ <answer> */

template<typename T>
tuple<int,int, T, T> resolver(const BinTree<T>& tree) { //estado, altura, min, max
    if (tree.empty()) {
        return { 1, 0, T(), T() };
    }
    else if (tree.left().empty() && tree.right().empty()) {
        return { 1, 1, tree.root(), tree.root()};
    }
    else if (tree.left().empty()) {
        auto [dr1, dr2, dr3, dr4] = resolver(tree.right());
        if (tree.root() >= dr3 || dr1 == -1 || dr2 > 1) {
            return { -1, 0, dr3, dr4 };
        }
        else {
            return { 1, dr2 + 1, min(tree.root(), dr3), max(tree.root(), dr4) };
        }

    }
    else if (tree.right().empty()) {
        auto [iz1, iz2, iz3, iz4] = resolver(tree.left());
        if (tree.root() <= iz4 || iz1 == -1 || iz2 > 1) {
            return { -1, 0, iz3, iz4 };
        }
        else {
            return { 1, iz2 + 1, min(tree.root(), iz3), max(tree.root(), iz4) };
        }
    }
    else {
        auto [iz1, iz2, iz3, iz4] = resolver(tree.left());
        auto [dr1, dr2, dr3, dr4] = resolver(tree.right());
        if (iz1 == -1 || dr1 == -1 || abs(iz2 - dr2) > 1 || iz4 >= tree.root() || dr3 <= tree.root()) {
            return { -1, 0, iz3,iz4 };
        }
        else {
            return { 1, max(iz2 + 1,dr2 + 1), min(tree.root(), iz3), max(tree.root(), dr4) };
        }
    }

}

bool resuelveCaso() {
    char tipo;
    cin >> tipo;
    if (!cin) {
        return false;
    }
    if (tipo == 'P') {
        BinTree<string> tree = read_tree<string>(cin);
        auto [sol1, sol2, sol3, sol4] = resolver<string>(tree);
        if (sol1 == -1) {
            cout << "NO\n";
        }
        else {
            cout << "SI\n";
        }
    }
    else {
        BinTree<int> tree = read_tree<int>(cin);
        auto [sol1, sol2, sol3, sol4] = resolver<int>(tree);
        if (sol1 == -1) {
            cout << "NO\n";
        }
        else {
            cout << "SI\n";
        }
    }
    return true;
}


/*@ </answer> */

int main()
{
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
    while (resuelveCaso());
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
