#ifndef _MPSXX_CXX_POINT_GROUP_D2H_H
#define _MPSXX_CXX_POINT_GROUP_D2H_H 1

namespace mpsxx {

namespace pointgroup {

class D2h {
private:
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) { ar & m_irrep; }

public:
  enum IRREP {
    Ag  = 0,
    B3u = 1,
    B2u = 2,
    B1g = 3,
    B1u = 4,
    B2g = 5,
    B3g = 6,
    Au  = 7
  };

  constexpr static size_t Nrep() { return 8; }

  const static D2h zero() { return D2h(Ag); }

  D2h(const IRREP& irrep = Ag) : m_irrep(irrep) { }

  bool operator== (const D2h& other) const { return m_irrep == other.m_irrep; }
  bool operator!= (const D2h& other) const { return m_irrep != other.m_irrep; }
  bool operator<  (const D2h& other) const { return m_irrep <  other.m_irrep; }
  bool operator>  (const D2h& other) const { return m_irrep >  other.m_irrep; }

  D2h operator* (const D2h& other) const { return D2h(m_product_table[m_irrep*Nrep()+other.m_irrep]); }

  const IRREP& Irrep() const { return m_irrep; }

private:
  //! Product table
  const static IRREP
    m_product_table[Nrep()*Nrep()];

  //! Irreducible representation
  IRREP
    m_irrep;
};

const static D2h::IRREP D2h::m_product_table[D2h::Nrep()*D2h::Nrep()] =
{
  Ag , B3u, B2u, B1g, B1u, B2g, B3g, Au ,
  B3u, Ag , B1g, B2u, B2g, B1u, Au , B3g,
  B2u, B1g, Ag , B3u, B3g, Au , B1u, B2g,
  B1g, B2u, B3u, Ag , Au , B3g, B2g, B1u,
  B1u, B2g, B3g, Au , Ag , B3u, B2u, B1g,
  B2g, B1u, Au , B3g, B3u, Ag , B1g, B2u,
  B3g, Au , B1u, B2g, B2u, B1g, Ag , B3u,
  Au , B3g, B2g, B1u, B1g, B2u, B3u, Ag
};

}; // namespace pointgroup

}; // namespace mpsxx

#endif // _MPSXX_CXX_POINT_GROUP_D2H_H