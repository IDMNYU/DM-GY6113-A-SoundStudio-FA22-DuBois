#include "testing.h"

namespace testing {

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
	DCBlock __m_dcblock_32;
	DCBlock __m_dcblock_37;
	DCBlock __m_dcblock_27;
	Data m_scale_6;
	Delay m_delay_4;
	Delay m_delay_2;
	Delay m_delay_1;
	Delay m_delay_3;
	Phasor __m_phasor_20;
	Sah __m_sah_38;
	Sah __m_sah_28;
	Sah __m_sah_31;
	Sah __m_sah_36;
	Sah __m_sah_33;
	Sah __m_sah_26;
	Sah __m_sah_21;
	Sah __m_sah_41;
	Sah __m_sah_23;
	int vectorsize;
	int __exception;
	t_sample m_knob4_thresh_8;
	t_sample m_knob5_fund_7;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample m_knob3_frequency_5;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)100000));
		m_delay_2.reset("m_delay_2", ((int)100000));
		m_delay_3.reset("m_delay_3", ((int)100000));
		m_delay_4.reset("m_delay_4", ((int)100000));
		m_knob3_frequency_5 = ((int)10);
		m_scale_6.reset("scale", ((int)12), ((int)1));
		m_knob5_fund_7 = ((int)60);
		m_knob4_thresh_8 = ((t_sample)0.5);
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
		int scale_dim = m_scale_6.dim;
		int scale_channels = m_scale_6.channels;
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
		t_sample rsub_90 = (((int)1) - m_knob4_thresh_8);
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			m_scale_6.write(((int)0), 0, 0);
			if ((!index_ignore_9)) {
				m_scale_6.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_10)) {
				m_scale_6.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_11)) {
				m_scale_6.write(((int)3), ((int)3), 0);
				
			};
			if ((!index_ignore_12)) {
				m_scale_6.write(((int)3), ((int)4), 0);
				
			};
			if ((!index_ignore_13)) {
				m_scale_6.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_14)) {
				m_scale_6.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_15)) {
				m_scale_6.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_16)) {
				m_scale_6.write(((int)8), ((int)8), 0);
				
			};
			if ((!index_ignore_17)) {
				m_scale_6.write(((int)8), ((int)9), 0);
				
			};
			if ((!index_ignore_18)) {
				m_scale_6.write(((int)10), ((int)10), 0);
				
			};
			if ((!index_ignore_19)) {
				m_scale_6.write(((int)10), ((int)11), 0);
				
			};
			t_sample noise_18 = noise();
			t_sample noise_5 = noise();
			t_sample noise_88 = noise();
			t_sample noise_62 = noise();
			t_sample noise_56 = noise();
			t_sample noise_43 = noise();
			t_sample noise_37 = noise();
			t_sample noise_24 = noise();
			t_sample noise_96 = noise();
			t_sample phasor_95 = __m_phasor_20(m_knob3_frequency_5, samples_to_seconds);
			t_sample sah_94 = __m_sah_21(noise_96, phasor_95, ((t_sample)0.5));
			int gt_93 = (sah_94 > rsub_90);
			int change_92 = __m_change_22(gt_93);
			int eq_91 = (change_92 == ((int)1));
			t_sample sah_19 = __m_sah_23(noise_18, eq_91, ((t_sample)0.5));
			t_sample sub_252 = (sah_19 - (-1));
			t_sample scale_249 = ((safepow((sub_252 * ((t_sample)0.5)), ((int)1)) * ((int)12)) + ((int)0));
			t_sample floor_16 = floor(scale_249);
			int index_trunc_24 = fixnan(floor(floor_16));
			bool index_ignore_25 = ((index_trunc_24 >= scale_dim) || (index_trunc_24 < 0));
			// samples scale channel 1;
			t_sample sample_scale_8 = (index_ignore_25 ? 0 : m_scale_6.read(index_trunc_24, 0));
			t_sample index_scale_9 = floor_16;
			t_sample sah_6 = __m_sah_26(noise_5, eq_91, ((t_sample)0.5));
			t_sample sub_256 = (sah_6 - (-1));
			t_sample scale_253 = ((safepow((sub_256 * ((t_sample)0.5)), ((int)1)) * ((int)3)) + ((int)0));
			t_sample floor_3 = floor(scale_253);
			t_sample mul_2 = (floor_3 * ((int)12));
			t_sample add_1 = (sample_scale_8 + mul_2);
			t_sample add_7 = (add_1 + m_knob5_fund_7);
			t_sample mtof_15 = mtof(add_7, ((int)440));
			t_sample rdiv_12 = safediv(samplerate, mtof_15);
			t_sample tap_14 = m_delay_4.read_linear(rdiv_12);
			t_sample dcblock_10 = __m_dcblock_27(tap_14);
			t_sample mul_11 = (dcblock_10 * ((t_sample)0.999));
			t_sample sah_89 = __m_sah_28(noise_88, eq_91, ((t_sample)0.5));
			t_sample sub_260 = (sah_89 - (-1));
			t_sample scale_257 = ((safepow((sub_260 * ((t_sample)0.5)), ((int)1)) * ((int)12)) + ((int)0));
			t_sample floor_86 = floor(scale_257);
			int index_trunc_29 = fixnan(floor(floor_86));
			bool index_ignore_30 = ((index_trunc_29 >= scale_dim) || (index_trunc_29 < 0));
			// samples scale channel 1;
			t_sample sample_scale_65 = (index_ignore_30 ? 0 : m_scale_6.read(index_trunc_29, 0));
			t_sample index_scale_66 = floor_86;
			t_sample sah_63 = __m_sah_31(noise_62, eq_91, ((t_sample)0.5));
			t_sample sub_264 = (sah_63 - (-1));
			t_sample scale_261 = ((safepow((sub_264 * ((t_sample)0.5)), ((int)1)) * ((int)3)) + ((int)0));
			t_sample floor_60 = floor(scale_261);
			t_sample mul_59 = (floor_60 * ((int)12));
			t_sample add_58 = (sample_scale_65 + mul_59);
			t_sample add_64 = (add_58 + m_knob5_fund_7);
			t_sample mtof_85 = mtof(add_64, ((int)440));
			t_sample rdiv_82 = safediv(samplerate, mtof_85);
			t_sample tap_84 = m_delay_3.read_linear(rdiv_82);
			t_sample dcblock_80 = __m_dcblock_32(tap_84);
			t_sample mul_81 = (dcblock_80 * ((t_sample)0.999));
			t_sample sah_57 = __m_sah_33(noise_56, eq_91, ((t_sample)0.5));
			t_sample sub_268 = (sah_57 - (-1));
			t_sample scale_265 = ((safepow((sub_268 * ((t_sample)0.5)), ((int)1)) * ((int)12)) + ((int)0));
			t_sample floor_54 = floor(scale_265);
			int index_trunc_34 = fixnan(floor(floor_54));
			bool index_ignore_35 = ((index_trunc_34 >= scale_dim) || (index_trunc_34 < 0));
			// samples scale channel 1;
			t_sample sample_scale_46 = (index_ignore_35 ? 0 : m_scale_6.read(index_trunc_34, 0));
			t_sample index_scale_47 = floor_54;
			t_sample sah_44 = __m_sah_36(noise_43, eq_91, ((t_sample)0.5));
			t_sample sub_272 = (sah_44 - (-1));
			t_sample scale_269 = ((safepow((sub_272 * ((t_sample)0.5)), ((int)1)) * ((int)3)) + ((int)0));
			t_sample floor_41 = floor(scale_269);
			t_sample mul_40 = (floor_41 * ((int)12));
			t_sample add_39 = (sample_scale_46 + mul_40);
			t_sample add_45 = (add_39 + m_knob5_fund_7);
			t_sample mtof_53 = mtof(add_45, ((int)440));
			t_sample rdiv_50 = safediv(samplerate, mtof_53);
			t_sample tap_52 = m_delay_2.read_linear(rdiv_50);
			t_sample dcblock_48 = __m_dcblock_37(tap_52);
			t_sample mul_49 = (dcblock_48 * ((t_sample)0.999));
			t_sample sah_38 = __m_sah_38(noise_37, eq_91, ((t_sample)0.5));
			t_sample sub_276 = (sah_38 - (-1));
			t_sample scale_273 = ((safepow((sub_276 * ((t_sample)0.5)), ((int)1)) * ((int)12)) + ((int)0));
			t_sample floor_35 = floor(scale_273);
			int index_trunc_39 = fixnan(floor(floor_35));
			bool index_ignore_40 = ((index_trunc_39 >= scale_dim) || (index_trunc_39 < 0));
			// samples scale channel 1;
			t_sample sample_scale_27 = (index_ignore_40 ? 0 : m_scale_6.read(index_trunc_39, 0));
			t_sample index_scale_28 = floor_35;
			t_sample sah_25 = __m_sah_41(noise_24, eq_91, ((t_sample)0.5));
			t_sample sub_280 = (sah_25 - (-1));
			t_sample scale_277 = ((safepow((sub_280 * ((t_sample)0.5)), ((int)1)) * ((int)3)) + ((int)0));
			t_sample floor_22 = floor(scale_277);
			t_sample mul_21 = (floor_22 * ((int)12));
			t_sample add_20 = (sample_scale_27 + mul_21);
			t_sample add_26 = (add_20 + m_knob5_fund_7);
			t_sample mtof_34 = mtof(add_26, ((int)440));
			t_sample rdiv_31 = safediv(samplerate, mtof_34);
			t_sample tap_33 = m_delay_1.read_linear(rdiv_31);
			t_sample dcblock_29 = __m_dcblock_42(tap_33);
			t_sample out1 = ((((dcblock_29 + dcblock_48) + dcblock_80) + in1) + dcblock_10);
			t_sample mul_30 = (dcblock_29 * ((t_sample)0.999));
			m_delay_4.write((in1 + mul_11));
			m_delay_3.write((in1 + mul_81));
			m_delay_2.write((mul_49 + in1));
			m_delay_1.write((mul_30 + in1));
			m_delay_1.step();
			m_delay_2.step();
			m_delay_3.step();
			m_delay_4.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			
		};
		return __exception;
		
	};
	inline void set_knob3_frequency(t_param _value) {
		m_knob3_frequency_5 = (_value < 1 ? 1 : (_value > 100 ? 100 : _value));
	};
	inline void set_scale(void * _value) {
		m_scale_6.setbuffer(_value);
	};
	inline void set_knob5_fund(t_param _value) {
		m_knob5_fund_7 = (_value < 30 ? 30 : (_value > 80 ? 80 : _value));
	};
	inline void set_knob4_thresh(t_param _value) {
		m_knob4_thresh_8 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob3_frequency(value); break;
		case 1: self->set_knob4_thresh(value); break;
		case 2: self->set_knob5_fund(value); break;
		case 3: self->set_scale(ref); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_frequency_5; break;
		case 1: *value = self->m_knob4_thresh_8; break;
		case 2: *value = self->m_knob5_fund_7; break;
		
		
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
	// initialize parameter 0 ("m_knob3_frequency_5")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_frequency";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_frequency_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_thresh_8")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_thresh_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fund_7")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fund";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fund_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 30;
	pi->outputmax = 80;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_scale_6")
	pi = self->__commonstate.params + 3;
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // testing::
