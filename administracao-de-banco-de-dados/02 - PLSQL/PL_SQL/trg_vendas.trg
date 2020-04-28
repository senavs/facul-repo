CREATE OR REPLACE TRIGGER trg_atualiza_estoque
AFTER INSERT ON venda 
FOR EACH ROW 
BEGIN
UPDATE produto
set qt_estoque = qt_estoque - :new.qt_item_vendido;
END;
/
