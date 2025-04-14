#include <iostream>
#include <map>
#include <cassert>

template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K, V> m_map;

public:
    // Construtor: associa todo o intervalo de K com o valor val
    template<typename V_forward>
    interval_map(V_forward&& val)
    : m_valBegin(std::forward<V_forward>(val)) {}

    // Assign valor val ao intervalo [keyBegin, keyEnd).
    // Se !(keyBegin < keyEnd), o intervalo é vazio e nada é feito.
    template<typename V_forward>
    void assign(K const& keyBegin, K const& keyEnd, V_forward&& val)
        requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value) {
        // if (keyBegin >= keyEnd)
        //     return ;

        // auto begin = m_map.lower_bound(keyBegin);
        // auto end = m_map.lower_bound(keyEnd);

        // V after;
        // if (end != m_map.end())
        //     after = end->second;
        // else {
        //     after = m_valBegin;

        //     if(!m_map.empty()) {
        //         auto itterate = m_map.upper_bound(keyEnd);
                
        //         if(itterate != m_map.begin())
        //             after = std::prev(itterate)->second;
        //     }
        // }
        // m_map.erase(begin, end);

        // if (operator[](keyBegin) != val) 
        //     m_map[keyBegin] = std::forward<V_forward>(val);

        // if (operator[](keyEnd) != after)
        //     m_map[keyEnd] = after;
//////////////////////////////////////////////
        
        // Checks if it is valid
        if (!(keyBegin < keyEnd))
            return;

        // Get begin value
        auto prev = m_map.lower_bound(keyBegin);
        auto beginVal = (prev == m_map.begin())
            ? m_valBegin
            : std::prev(prev)->second;

        // Get end value
        auto next = m_map.upper_bound(keyEnd);
        auto endVal = (next == m_map.begin())
            ? m_valBegin
            : std::prev(next)->second;

        // With this, we can store the values from the start to the end, and see if it is needed to add to the map
        // Erase affected range, excluding the same letters
        m_map.erase(prev, next);

        // Insert new interval only if value changes
        if (!(val == beginVal))
            m_map.emplace(keyBegin, std::forward<V_forward>(val));

        // Insert end marker only if value changes
        if (!(endVal == val))
            m_map.emplace(keyEnd, std::move(endVal));
    }

    // Operador [] para obter o valor associado a uma chave
    V const& operator[](K const& key) const {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin()) {
            return m_valBegin;
        } else {
            return (--it)->second;
        }
    }
};

// Função para testar a classe interval_map
void IntervalMapTest() {
	// Criação com valor por defeito
	// interval_map<int, std::string> imap("default");

	// // Teste 1: valores antes de qualquer atribuição devem ser "default"
	// assert(imap[0] == "default");
	// assert(imap[100] == "default");

	// // Teste 2: simular inserções (assumindo que assign funciona)
    // imap.assign(10, 20, std::string("A"));
    // imap.assign(30, 40, std::string("B"));
    // imap.assign(50, 50, std::string("C"));

	// // Dentro dos intervalos
	// assert(imap[10] == "A");
	// assert(imap[15] == "A");
	// assert(imap[19] == "A");

	// assert(imap[30] == "B");
	// assert(imap[35] == "B");
	// assert(imap[39] == "B");

	// // // Fora dos intervalos
	// assert(imap[9] == "default");
	// assert(imap[20] == "default");
	// assert(imap[29] == "default");
	// assert(imap[40] == "default");

	// // // Intervalo vazio (não deve alterar nada)
	// imap.assign(50, 50, std::string("C"));
	// assert(imap[50] == "default");


    interval_map<int, std::string> imap("Z");  // valor inicial = "Z"

    // Teste 1: Intervalo normal
    imap.assign(10, 20, std::string("A"));
    assert(imap[9] == "Z");
    assert(imap[11] == "A");
    assert(imap[19] == "A");
    assert(imap[20] == "Z");

    // Teste 2: Intervalo adjacente
    imap.assign(15, 30, std::string("B"));
    assert(imap[18] == "B");
    assert(imap[13] == "A");
    assert(imap[29] == "B");
    assert(imap[30] == "Z");

    // Teste 3: Sobreposição parcial (meio do primeiro)
    imap.assign(15, 25, std::string("C"));
    assert(imap[14] == "A");
    assert(imap[15] == "C");
    assert(imap[24] == "C");
    assert(imap[25] == "B");
    assert(imap[30] == "Z");

    // Teste 4: Reatribuir o mesmo valor não deve mudar estrutura
    imap.assign(25, 30, std::string("B"));
    assert(imap[26] == "B");
    assert(imap[26] == "B");
    assert(imap[26] == "B");

    
    // Teste 5: Intervalo vazio (não deve mudar nada)
    imap.assign(50, 50, std::string("X"));
    assert(imap[49] == "Z");
    assert(imap[50] == "Z");

    // Teste 6: Novo valor a meio do nada
    imap.assign(100, 200, std::string("D"));
    assert(imap[99] == "Z");
    assert(imap[100] == "D");
    assert(imap[150] == "D");
    assert(imap[199] == "D");
    assert(imap[200] == "Z");

    std::cout << "✅ Todos os testes passaram!" << std::endl;
}


int main() {
    IntervalMapTest();
    return 0;
}
