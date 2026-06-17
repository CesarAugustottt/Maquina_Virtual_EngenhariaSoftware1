#include "unit_System.h"
#include "../../src/SystemImpl.h"
#include <cassert>


#define DEBUGING
#ifdef DEBUGING
    extern int numHandleCreated;
    extern int numHandleDeleted;
    extern int numBodyCreated;
    extern int numBodyDeleted;
#endif

bool Unit_System::defaultConstructor(void) {
    SystemHandle s1;
    assert(s1.pImpl_->name == "");
    assert(s1.pImpl_->value == 0.0);
    return true;
}

bool Unit_System::constructor(void) {
    SystemHandle s2("Sys", 10.0);
    assert(s2.pImpl_->name == "Sys");
    assert(s2.pImpl_->value == 10.0);
    return true;
}

bool Unit_System::destructor(void) {
    SystemHandle* s = new SystemHandle();
    delete s;
    return true;
}

bool Unit_System::getName(void) {
    SystemHandle s;
    s.pImpl_->name = "TestName";
    assert(s.getName() == "TestName");
    return true;
}

bool Unit_System::setName(void) {
    SystemHandle s;
    s.setName("NewName");
    assert(s.pImpl_->name == "NewName");
    return true;
}

bool Unit_System::getValue(void) {
    SystemHandle s;
    s.pImpl_->value = 10.0;
    assert(s.getValue() == 10.0);
    return true;
}

bool Unit_System::setValue(void) {
    SystemHandle s;
    s.setValue(100.0);
    assert(s.pImpl_->value == 100.0);
    return true;
}

bool Unit_System::copyConstructor(void) {
    SystemHandle original;
    original.pImpl_->name = "Original";
    original.pImpl_->value = 10.0;
    
    SystemHandle copy(original);
    assert(copy.pImpl_->name == "Original");
    assert(copy.pImpl_->value == 10.0);
    return true;
}

bool Unit_System::assignmentOperator(void) {
    SystemHandle original;
    original.pImpl_->name = "Original";
    original.pImpl_->value = 10.0;
    
    SystemHandle destination;
    destination = original;

    assert(destination.pImpl_->name == "Original");
    assert(destination.pImpl_->value == 10.0);
    return true;
}

bool Unit_System::handleBodyTest(void) {
    //resetar os contadores antes de começar o teste
    #ifdef DEBUGING
        numHandleCreated = 0;
        numHandleDeleted = 0;
        numBodyCreated = 0;
        numBodyDeleted = 0;
    #endif

    //teste 1:
    {
        SystemHandle s1("Sistema 1", 10.0);
        SystemHandle s2("Sistema 2", 20.0);

        //deve ter criado cada um 2 body e 2 handle
        assert(numHandleCreated == 2);
        assert(numBodyCreated == 2);
        assert(numHandleDeleted == 0);
        assert(numBodyDeleted == 0);

        //Atribuiçaõ, s1 aponta para s2
        s1 = s2; 

        // Como o pImpl_ antigo de s1 perdeu a referencia, ele é deletado
        assert(numBodyDeleted == 1); 
    } 
    // Saindo do bloco, s1 e s2 ssão destruidos

    assert(numHandleCreated == 2);
    assert(numHandleDeleted == 2);
    assert(numBodyCreated == 2);
    assert(numBodyDeleted == 2);

    //resetar os contadores
    #ifdef DEBUGING
        numHandleCreated = 0; 
        numHandleDeleted = 0;
        numBodyCreated = 0; 
        numBodyDeleted = 0;
    #endif

    //teste 2:
    {
        SystemHandle s3("Original", 50.0); // +1 handle e +1 body.
        
        {
            //construtor de copia ( +1 handle, 0 body)
            SystemHandle s4(s3);
            assert(numHandleCreated == 2);
            assert(numBodyCreated == 1); 
        } // s4 morre aqui, + 1 delete de handle
        
        assert(numHandleDeleted == 1);
        assert(numBodyDeleted == 0);
    } 
    // saindo s3 morre (+1 handle e +1 body deletado)

    assert(numHandleDeleted == 2);
    assert(numBodyDeleted == 1);

    //resetar os contadores
    #ifdef DEBUGING
        numHandleCreated = 0; 
        numHandleDeleted = 0;
        numBodyCreated = 0; 
        numBodyDeleted = 0;
    #endif

    //teste 3:
    {
        SystemHandle* p1 = new SystemHandle("Ponteiro 1", 100.0); // +1 handle e +1 body
        SystemHandle* p2 = new SystemHandle("Ponteiro 2", 200.0); // +1 handle e +1 body

        assert(numHandleCreated == 2);
        assert(numBodyCreated == 2);

        // Atribuição de ponteiros
        *p1 = *p2;

        // O conteúdo do handle de p1 agora aponta para o body de p2.
        // O body antigo de p1 foi morto
        assert(numBodyDeleted == 1);
        assert(numHandleDeleted == 0); // handle continua vivo

        // Deletar os ponteiros 
        delete p1; // p1 morre.
        assert(numHandleDeleted == 1);
        assert(numBodyDeleted == 1); // p1 do body já tinha morrido

        delete p2; // p2 morre
        assert(numHandleDeleted == 2);
        assert(numBodyDeleted == 2); // ambos os corpos foram destruidos
    }

    return true;
}

bool Unit_System::regressiveTest(void) {
    assert(defaultConstructor());
    assert(constructor());
    assert(destructor());
    assert(getName());
    assert(setName());
    assert(getValue());
    assert(setValue());
    assert(copyConstructor());
    assert(assignmentOperator());

    assert(handleBodyTest());
    return true;
}
