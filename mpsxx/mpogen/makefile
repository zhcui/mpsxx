CXX=/homec/naokin/gnu/gcc/4.8.4/bin/g++ -std=c++11
CXXFLAGS=-g -O3 -openmp -D_DEFAULT_QUANTUM -D_ENABLE_DEFAULT_QUANTUM -D_HAS_CBLAS -D_HAS_INTEL_MKL

BLASDIR=/home100/opt/intel/mkl
BLASINC=-I$(BLASDIR)/include
BLASLIB=-L$(BLASDIR)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_sequential

BOOSTINC=-I/homec/naokin/boost/1.54.0/include
BOOSTLIB=-L/homec/naokin/boost/1.54.0/lib -lboost_serialization

BTASDIR= $(HOME)/devel/btas
BTASINC=-I. -I.. -I$(BTASDIR)/include
BTASLIB= $(BTASDIR)/lib/libbtas.a

INCLUDEFLAGS= $(BLASINC) $(BOOSTINC) $(BTASINC)
LIBRARYFLAGS= $(BLASLIB) $(BOOSTLIB)

SRC_MPOGEN  = bit_operator_type.C boundary_opinfo.C gen_qc_operators.C gen_site_operator.C get_product_ops.C integral_component.C ../driver/parsing_integral.C prime_operators.C mpogen.C ../driver/fileio.C compress_qc_mpos.C
SRC_NAIVE_MPOGEN  = gen_qc_naive_mpos.C compress_qc_mpos.C ../driver/parsing_integral.C naive_mpogen.C ../driver/fileio.C
SRC_HUBGEN  = bit_operator_type.C boundary_opinfo.C gen_hubbard_operators.C gen_site_operator.C get_product_ops.C integral_component.C ../driver/parsing_integral.C prime_operators.C hubgen.C ../driver/fileio.C
SRC_TESTGEN = bit_operator_type.C boundary_opinfo.C get_product_ops.C testgen.C

OBJ_MPOGEN  = $(SRC_MPOGEN:.C=.o)
OBJ_NAIVE_MPOGEN  = $(SRC_NAIVE_MPOGEN:.C=.o)
OBJ_HUBGEN  = $(SRC_HUBGEN:.C=.o)
OBJ_TESTGEN = $(SRC_TESTGEN:.C=.o)

.C.o	:
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) -c $< -o $@

all	: mpogen naive_mpogen hubgen

mpogen	: $(OBJ_MPOGEN)
	$(CXX) $(CXXFLAGS) -o mpogen.x $(OBJ_MPOGEN) $(BTASLIB) $(LIBRARYFLAGS)

naive_mpogen	: $(OBJ_NAIVE_MPOGEN)
	$(CXX) $(CXXFLAGS) -o naive_mpogen.x $(OBJ_NAIVE_MPOGEN) $(BTASLIB) $(LIBRARYFLAGS)

hubgen	: $(OBJ_HUBGEN)
	$(CXX) $(CXXFLAGS) -o hubgen.x $(OBJ_HUBGEN) $(BTASLIB) $(LIBRARYFLAGS)

#testgen	: $(OBJ_TESTGEN)
#	$(CXX) $(CXXFLAGS) -o testgen.x $(OBJ_TESTGEN) $(BTASLIB) $(LIBRARYFLAGS)

clean	:
	rm *.o; rm *.x; rm *.a;
