class Ingresso {
public:
    Ingresso(Sessao* sessao, bool meioIngresso);
    const Sessao* getSessao() const { return sessao; }
    bool isMeioIngresso() const { return meioIngresso; }

private:
    Sessao* sessao;
    bool meioIngresso;
};