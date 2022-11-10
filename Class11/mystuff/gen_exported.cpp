#include "gen_exported.h"

namespace gen_exported {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2022 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Change __m_change_22;
	DCBlock __m_dcblock_42;
	DCBlock __m_dcblock_27;
	DCBlock __m_dcblock_32;
	DCBlock __m_dcblock_37;
	Data m_scale_8;
	Delay m_delay_4;
	Delay m_delay_3;
	Delay m_delay_2;
	Delay m_delay_1;
	Phasor __m_phasor_20;
	Sah __m_sah_28;
	Sah __m_sah_33;
	Sah __m_sah_36;
	Sah __m_sah_31;
	Sah __m_sah_38;
	Sah __m_sah_26;
	Sah __m_sah_21;
	Sah __m_sah_41;
	Sah __m_sah_23;
	int vectorsize;
	int __exception;
	t_sample m_fund_7;
	t_sample m_thresh_6;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample m_frequency_5;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)100000));
		m_delay_2.reset("m_delay_2", ((int)100000));
		m_delay_3.reset("m_delay_3", ((int)100000));
		m_delay_4.reset("m_delay_4", ((int)100000));
		m_frequency_5 = ((int)10);
		m_thresh_6 = ((t_sample)0.5);
		m_fund_7 = ((int)60);
		m_scale_8.reset("scale", ((int)12), ((int)1));
		samples_to_seconds = (1 / samplerate);
		__m_phasor_20.reset(0);
		__m_sah_21.reset(0);
		__m_change_22.reset(0);
		__m_sah_23.reset(0);
		__m_sah_26.reset(0);
		__m_dcblock_27.reset();
		__m_sah_28.reset(0);
		__m_sah_31.reset(0);
		__m_dcblock_32.reset();
		__m_sah_33.reset(0);
		__m_sah_36.reset(0);
		__m_dcblock_37.reset();
		__m_sah_38.reset(0);
		__m_sah_41.reset(0);
		__m_dcblock_42.reset();
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int scale_dim = m_scale_8.dim;
		int scale_channels = m_scale_8.channels;
		bool index_ignore_9 = (((int)1) >= scale_dim);
		bool index_ignore_10 = (((int)2) >= scale_dim);
		bool index_ignore_11 = (((int)3) >= scale_dim);
		bool index_ignore_12 = (((int)4) >= scale_dim);
		bool index_ignore_13 = (((int)5) >= scale_dim);
		bool index_ignore_14 = (((int)6) >= scale_dim);
		bool index_ignore_15 = (((int)7) >= scale_dim);
		bool index_ignore_16 = (((int)8) >= scale_dim);
		bool index_ignore_17 = (((int)9) >= scale_dim);
		bool index_ignore_18 = (((int)10) >= scale_dim);
		bool index_ignore_19 = (((int)11) >= scale_dim);
		t_sample rsub_130 = (((int)1) - m_thresh_6);
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			m_scale_8.write(((int)0), 0, 0);
			if ((!index_ignore_9)) {
				m_scale_8.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_10)) {
				m_scale_8.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_11)) {
				m_scale_8.write(((int)3), ((int)3), 0);
				
			};
			if ((!index_ignore_12)) {
				m_scale_8.write(((int)3), ((int)4), 0);
				
			};
			if ((!index_ignore_13)) {
				m_scale_8.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_14)) {
				m_scale_8.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_15)) {
				m_scale_8.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_16)) {
				m_scale_8.write(((int)8), ((int)8), 0);
				
			};
			if ((!index_ignore_17)) {
				m_scale_8.write(((int)8), ((int)9), 0);
				
			};
			if ((!index_ignore_18)) {
				m_scale_8.write(((int)10), ((int)10), 0);
				
			};
			if ((!index_ignore_19)) {
				m_scale_8.write(((int)10), ((int)11), 0);
				
			};
			t_sample noise_174 = noise();
			t_sample noise_890 = noise();
			t_sample noise_1617 = noise();
			t_sample noise_1604 = noise();
			t_sample noise_1648 = noise();
			t_sample noise_1635 = noise();
			t_sample noise_1679 = noise();
			t_sample noise_1666 = noise();
			t_sample noise_120 = noise();
			t_sample phasor_121 = __m_phasor_20(m_frequency_5, samples_to_seconds);
			t_sample sah_123 = __m_sah_21(noise_120, phasor_121, ((t_sample)0.5));
			int gt_129 = (sah_123 > rsub_130);
			int change_125 = __m_change_22(gt_129);
			int eq_475 = (change_125 == ((int)1));
			t_sample sah_173 = __m_sah_23(noise_174, eq_475, ((t_sample)0.5));
			t_sample sub_1908 = (sah_173 - (-1));
			t_sample scale_1905 = ((safepow((sub_1908 * ((t_sample)0.5)), ((int)1)) * ((int)12)) + ((int)0));
			t_sample floor_287 = floor(scale_1905);
			int index_trunc_24 = fixnan(floor(floor_287));
			bool index_ignore_25 = ((index_trunc_24 >= scale_dim) || (index_trunc_24 < 0));
			// samples scale channel 1;
			t_sample sample_scale_691 = (index_ignore_25 ? 0 : m_scale_8.read(index_trunc_24, 0));
			t_sample index_scale_692 = floor_287;
			t_sample sah_891 = __m_sah_26(noise_890, eq_475, ((t_sample)0.5));
			t_sample sub_1912 = (sah_891 - (-1));
			t_sample scale_1909 = ((safepow((sub_1912 * ((t_sample)0.5)), ((int)1)) * ((int)3)) + ((int)0));
			t_sample floor_954 = floor(scale_1909);
			t_sample mul_979 = (floor_954 * ((int)12));
			t_sample add_1004 = (sample_scale_691 + mul_979);
			t_sample add_717 = (add_1004 + m_fund_7);
			t_sample mtof_1077 = mtof(add_717, ((int)440));
			t_sample rdiv_193 = safediv(samplerate, mtof_1077);
			t_sample tap_335 = m_delay_4.read_linear(rdiv_193);
			t_sample dcblock_542 = __m_dcblock_27(tap_335);
			t_sample mul_504 = (dcblock_542 * ((t_sample)0.999));
			t_sample sah_1618 = __m_sah_28(noise_1617, eq_475, ((t_sample)0.5));
			t_sample sub_1916 = (sah_1618 - (-1));
			t_sample scale_1913 = ((safepow((sub_1916 * ((t_sample)0.5)), ((int)1)) * ((int)12)) + ((int)0));
			t_sample floor_1615 = floor(scale_1913);
			int index_trunc_29 = fixnan(floor(floor_1615));
			bool index_ignore_30 = ((index_trunc_29 >= scale_dim) || (index_trunc_29 < 0));
			// samples scale channel 1;
			t_sample sample_scale_1607 = (index_ignore_30 ? 0 : m_scale_8.read(index_trunc_29, 0));
			t_sample index_scale_1608 = floor_1615;
			t_sample sah_1605 = __m_sah_31(noise_1604, eq_475, ((t_sample)0.5));
			t_sample sub_1920 = (sah_1605 - (-1));
			t_sample scale_1917 = ((safepow((sub_1920 * ((t_sample)0.5)), ((int)1)) * ((int)3)) + ((int)0));
			t_sample floor_1602 = floor(scale_1917);
			t_sample mul_1601 = (floor_1602 * ((int)12));
			t_sample add_1600 = (sample_scale_1607 + mul_1601);
			t_sample add_1606 = (add_1600 + m_fund_7);
			t_sample mtof_1614 = mtof(add_1606, ((int)440));
			t_sample rdiv_1611 = safediv(samplerate, mtof_1614);
			t_sample tap_1613 = m_delay_3.read_linear(rdiv_1611);
			t_sample dcblock_1609 = __m_dcblock_32(tap_1613);
			t_sample mul_1610 = (dcblock_1609 * ((t_sample)0.999));
			t_sample sah_1649 = __m_sah_33(noise_1648, eq_475, ((t_sample)0.5));
			t_sample sub_1924 = (sah_1649 - (-1));
			t_sample scale_1921 = ((safepow((sub_1924 * ((t_sample)0.5)), ((int)1)) * ((int)12)) + ((int)0));
			t_sample floor_1646 = floor(scale_1921);
			int index_trunc_34 = fixnan(floor(floor_1646));
			bool index_ignore_35 = ((index_trunc_34 >= scale_dim) || (index_trunc_34 < 0));
			// samples scale channel 1;
			t_sample sample_scale_1638 = (index_ignore_35 ? 0 : m_scale_8.read(index_trunc_34, 0));
			t_sample index_scale_1639 = floor_1646;
			t_sample sah_1636 = __m_sah_36(noise_1635, eq_475, ((t_sample)0.5));
			t_sample sub_1928 = (sah_1636 - (-1));
			t_sample scale_1925 = ((safepow((sub_1928 * ((t_sample)0.5)), ((int)1)) * ((int)3)) + ((int)0));
			t_sample floor_1633 = floor(scale_1925);
			t_sample mul_1632 = (floor_1633 * ((int)12));
			t_sample add_1631 = (sample_scale_1638 + mul_1632);
			t_sample add_1637 = (add_1631 + m_fund_7);
			t_sample mtof_1645 = mtof(add_1637, ((int)440));
			t_sample rdiv_1642 = safediv(samplerate, mtof_1645);
			t_sample tap_1644 = m_delay_2.read_linear(rdiv_1642);
			t_sample dcblock_1640 = __m_dcblock_37(tap_1644);
			t_sample mul_1641 = (dcblock_1640 * ((t_sample)0.999));
			t_sample sah_1680 = __m_sah_38(noise_1679, eq_475, ((t_sample)0.5));
			t_sample sub_1932 = (sah_1680 - (-1));
			t_sample scale_1929 = ((safepow((sub_1932 * ((t_sample)0.5)), ((int)1)) * ((int)12)) + ((int)0));
			t_sample floor_1677 = floor(scale_1929);
			int index_trunc_39 = fixnan(floor(floor_1677));
			bool index_ignore_40 = ((index_trunc_39 >= scale_dim) || (index_trunc_39 < 0));
			// samples scale channel 1;
			t_sample sample_scale_1669 = (index_ignore_40 ? 0 : m_scale_8.read(index_trunc_39, 0));
			t_sample index_scale_1670 = floor_1677;
			t_sample sah_1667 = __m_sah_41(noise_1666, eq_475, ((t_sample)0.5));
			t_sample sub_1936 = (sah_1667 - (-1));
			t_sample scale_1933 = ((safepow((sub_1936 * ((t_sample)0.5)), ((int)1)) * ((int)3)) + ((int)0));
			t_sample floor_1664 = floor(scale_1933);
			t_sample mul_1663 = (floor_1664 * ((int)12));
			t_sample add_1662 = (sample_scale_1669 + mul_1663);
			t_sample add_1668 = (add_1662 + m_fund_7);
			t_sample mtof_1676 = mtof(add_1668, ((int)440));
			t_sample rdiv_1673 = safediv(samplerate, mtof_1676);
			t_sample tap_1675 = m_delay_1.read_linear(rdiv_1673);
			t_sample dcblock_1671 = __m_dcblock_42(tap_1675);
			t_sample out1 = ((((dcblock_1671 + dcblock_1640) + dcblock_1609) + in1) + dcblock_542);
			t_sample mul_1672 = (dcblock_1671 * ((t_sample)0.999));
			m_delay_4.write((in1 + mul_504));
			m_delay_3.write((in1 + mul_1610));
			m_delay_2.write((in1 + mul_1641));
			m_delay_1.write((in1 + mul_1672));
			m_delay_1.step();
			m_delay_2.step();
			m_delay_3.step();
			m_delay_4.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			
		};
		return __exception;
		
	};
	inline void set_frequency(t_param _value) {
		m_frequency_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_thresh(t_param _value) {
		m_thresh_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_fund(t_param _value) {
		m_fund_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_scale(void * _value) {
		m_scale_8.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 1;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 4; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_frequency(value); break;
		case 1: self->set_fund(value); break;
		case 2: self->set_scale(ref); break;
		case 3: self->set_thresh(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_frequency_5; break;
		case 1: *value = self->m_fund_7; break;
		
		case 3: *value = self->m_thresh_6; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(4 * sizeof(ParamInfo));
	self->__commonstate.numparams = 4;
	// initialize parameter 0 ("m_frequency_5")
	pi = self->__commonstate.params + 0;
	pi->name = "frequency";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_frequency_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_fund_7")
	pi = self->__commonstate.params + 1;
	pi->name = "fund";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_fund_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_scale_8")
	pi = self->__commonstate.params + 2;
	pi->name = "scale";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_thresh_6")
	pi = self->__commonstate.params + 3;
	pi->name = "thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_thresh_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // gen_exported::
