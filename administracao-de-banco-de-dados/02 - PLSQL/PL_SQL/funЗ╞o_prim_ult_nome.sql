CREATE OR REPLACE
  function junta_prim_ult_nome (p_nome in varchar2)
        return varchar2 is
  ---------------------------------------------------------------
nome_aux varchar2(200):=p_nome;
prim_nome varchar2(30);
ult_nome varchar2(30);
prm_ult_nome varchar2(61);
posicao1 number:=0;
posicao2 number:=0;

begin
posicao1 := instr(nome_aux,' ',1) - 1;
posicao2 := instr(nome_aux,' ',-1) + 1;
prim_nome := substr(nome_aux, 1, posicao1);
ult_nome := substr(nome_aux, posicao2, length(nome_aux) - posicao2 + 1);

prm_ult_nome := prim_nome || ' ' || ult_nome;

Return(prm_ult_nome);

End;

------------
select junta_prim_ult_nome('Joaquim José da Silva Xavier') as teste
from dual;

TESTE
Joaquim Xavier

------------
select nm_muni, junta_prim_ult_nome(nm_muni) as nm_muni_abrev
from muni_bge;

NM_MUNI	NM_MUNI_ABREV
Miguel Alves	Miguel Alves
Miguel Leão	Miguel Leão
Milton Brandão	Milton Brandão
Monsenhor Gil	Monsenhor Gil
Monsenhor Hipólito	Monsenhor Hipólito
Monte Alegre do Piauí	Monte Piauí
Morro Cabeça no Tempo	Morro Tempo
Morro do Chapéu do Piauí	Morro Piauí
Murici dos Portelas	Murici Portelas
Nazaré do Piauí	Nazaré Piauí

Há mais de 10 linhas disponíveis. Aumente o seletor de linhas para ver mais linhas.

