/*==============================================================*/
/* DBMS name:      ORACLE Version 10g                           */
/* Created on:     6/8/2009 20:38:05                            */
/*==============================================================*/


/*==============================================================*/
/* Table: MUNI_IBGE                                             */
/*==============================================================*/
create table MUNI_IBGE  (
   ID_MUNI_IBGE         NUMBER(7)                       not null,
   NM_MUNI              VARCHAR2(200),
   ID_UF_IBGE           NUMBER(2),
   POPULACAO_1991       NUMBER(10),
   POPULACAO_2000       NUMBER(10),
   constraint PK_MUNI_IBGE primary key (ID_MUNI_IBGE)
);

comment on table MUNI_IBGE is
'Municípios brasileiros';

/*==============================================================*/
/* Table: REGIAO_IBGE                                           */
/*==============================================================*/
create table REGIAO_IBGE  (
   ID_REGIAO_IBGE       NUMBER(1)                       not null,
   NM_REGIAO_IBGE       VARCHAR2(50)                    not null,
   constraint PK_REGIAO_IBGE primary key (ID_REGIAO_IBGE)
);

comment on table REGIAO_IBGE is
'Regiões geográficas do IBGE';

/*==============================================================*/
/* Table: UF_IBGE                                               */
/*==============================================================*/
create table UF_IBGE  (
   ID_UF_IBGE           NUMBER(2)                       not null,
   ID_REGIAO_IBGE       NUMBER(1),
   SIGLA_UF             CHAR(2),
   NM_UF                VARCHAR2(100),
   constraint PK_UF_IBGE primary key (ID_UF_IBGE)
);

comment on table UF_IBGE is
'Unidades da Federação';

