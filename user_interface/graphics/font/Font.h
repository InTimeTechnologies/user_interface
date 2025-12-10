#pragma once

// Dependencies | std
#include <string>

// Dependencies | OS
#include <Windows.h>

namespace ui {
	class Font {
		public:
			// Enums
			enum class Weight : int {
				DONT_CARE = FW_DONTCARE,
				THIN = FW_THIN,
				EXTRA_LIGHT = FW_EXTRALIGHT,
				LIGHT = FW_LIGHT,
				NORMAL = FW_NORMAL,
				MEDIUM = FW_MEDIUM,
				SEMI_BOLD = FW_SEMIBOLD,
				BOLD = FW_BOLD,
				EXTRA_BOLD = FW_EXTRABOLD,
				HEAVY = FW_HEAVY,

				// Defines not included in the enum class
				/*
				#define PANOSE_COUNT               10
				#define PAN_FAMILYTYPE_INDEX        0
				#define PAN_SERIFSTYLE_INDEX        1
				#define PAN_WEIGHT_INDEX            2
				#define PAN_PROPORTION_INDEX        3
				#define PAN_CONTRAST_INDEX          4
				#define PAN_STROKEVARIATION_INDEX   5
				#define PAN_ARMSTYLE_INDEX          6
				#define PAN_LETTERFORM_INDEX        7
				#define PAN_MIDLINE_INDEX           8
				#define PAN_XHEIGHT_INDEX           9

				#define PAN_CULTURE_LATIN           0
				*/
			};

			//constexpr Weight operator|(Weight a, Weight b) {
			//	return static_cast<Weight>(static_cast<int>(a) | static_cast<int>(b));
			//}
			//constexpr Weight operator&(Weight a, Weight b) {
			//	return static_cast<Weight>(static_cast<int>(a) & static_cast<int>(b));
			//}
			//constexpr Weight& operator|=(Weight& a, Weight b) {
			//	a = a | b;
			//	return a;
			//}
			//constexpr Weight& operator&=(Weight& a, Weight b) {
			//	a = a & b;
			//	return a;
			//}
			//constexpr Weight operator~(Weight a) {
			//	return static_cast<Weight>(~static_cast<int>(a));
			//}

			enum class Charset : int {
				ANSI = ANSI_CHARSET,
				DEFAULT = DEFAULT_CHARSET,
				SYMBOLD = SYMBOL_CHARSET,
				SHIFT_JIS = SHIFTJIS_CHARSET,
				HANGEUL = HANGEUL_CHARSET,
				HANGUL = HANGUL_CHARSET,
				GB2312 = GB2312_CHARSET,
				CHINESEBIG5 = CHINESEBIG5_CHARSET,
				EOM = OEM_CHARSET,

				JOHAB = JOHAB_CHARSET,
				HEBREW = HEBREW_CHARSET,
				ARABIC = ARABIC_CHARSET,
				GREEK = GREEK_CHARSET,
				TURKISH = TURKISH_CHARSET,
				VIETNAMESE = VIETNAMESE_CHARSET,
				THAI = THAI_CHARSET,
				EASTERN_EUROPE = EASTEUROPE_CHARSET,
				RUSSIAN = RUSSIAN_CHARSET,

				MAC = MAC_CHARSET,
				BALTIC = BALTIC_CHARSET

				//LATIN1_FS = FS_LATIN1,
				//LATIN2_FS = FS_LATIN2,
				//CYRILLIC_FS = FS_CYRILLIC,
				//GREEK_FS = FS_GREEK,
				//TURKISH_FS = FS_TURKISH,
				//HEBREW_FS = FS_HEBREW,
				//ARABIC_FS = FS_ARABIC,
				//BALTIC = FS_BALTIC,
				//VIETNAMESE_FS = FS_VIETNAMESE,
				//THAT_FS = FS_THAI,
				//JIS_JAPAN_FS = FS_JISJAPAN,
				//CHINESE_SIMP_FS = FS_CHINESESIMP,
				//WANSUNG_FS = FS_WANSUNG,
				//CINESE_TRAD_FS = FS_CHINESETRAD,
				//JOHAB_FS = FS_JOHAB,
				//SYMBOL_FS = FS_SYMBOL
			};

			enum class OutPrecision {
				DEFAULT = OUT_DEFAULT_PRECIS,
				STRING = OUT_STRING_PRECIS,
				CHARACTER = OUT_CHARACTER_PRECIS,
				STROKE = OUT_STROKE_PRECIS,
				TT = OUT_TT_PRECIS,
				DEVICE = OUT_DEVICE_PRECIS,
				RASTER = OUT_RASTER_PRECIS,
				TT_ONLY = OUT_TT_ONLY_PRECIS,
				OUTLINE = OUT_OUTLINE_PRECIS,
				SCREEN = OUT_SCREEN_OUTLINE_PRECIS,
				PS_ONLY = OUT_PS_ONLY_PRECIS

				// Precisions not included:
				/*
				#define CLIP_DEFAULT_PRECIS     0
				#define CLIP_CHARACTER_PRECIS   1
				#define CLIP_STROKE_PRECIS      2
				#define CLIP_MASK               0xf
				#define CLIP_LH_ANGLES          (1<<4)
				#define CLIP_TT_ALWAYS          (2<<4)
				#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
				#define CLIP_DFA_DISABLE        (4<<4)
				#endif // (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
				#define CLIP_EMBEDDED           (8<<4)
				*/
			};

			enum class Quality {
				DEFAULT = DEFAULT_QUALITY,
				DRAFT = DRAFT_QUALITY,
				PROOF = PROOF_QUALITY,
				NON_ANTIALIASED = NONANTIALIASED_QUALITY,
				ANTIALIASED = ANTIALIASED_QUALITY,
				CLEARTYPE = CLEARTYPE_QUALITY,
				CLEARTYPE_NATURAL = CLEARTYPE_NATURAL_QUALITY
			};

			enum class ClipPrecision {
				DEFAULT = CLIP_DEFAULT_PRECIS,
				CHARACTER = CLIP_CHARACTER_PRECIS,
				STROKE = CLIP_STROKE_PRECIS,
				MASK = CLIP_MASK,
				LH_ANGLES = CLIP_LH_ANGLES,
				TT_ALWAYS = CLIP_TT_ALWAYS,

				#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
				DFA_DISABLE = CLIP_DFA_DISABLE,
				#endif

				EMBEDDED = CLIP_EMBEDDED
			};

			enum class Pitch {
				DEFAULT = 0,
				FIXED = 1,
				VARIABLE = 2
			};

			enum class Family {
				DECORATIVE = FF_DECORATIVE,
				DONTCARE = FF_DONTCARE,
				MODERN = FF_MODERN,
				ROMAN = FF_ROMAN,
				SCRIPT = FF_SCRIPT,
				SWISS = FF_SWISS
			};

		// Static
		public:
			// Properties
			static int s_defaultHeight;
			static int s_defaultWidth;
			static int s_defaultAngle;
			static int s_defaultOrientation;
			static Weight s_defaultFontWeight;
			static bool s_defaultItalic;
			static bool s_defaultStrikeOut;
			static bool s_defaultUnderline;
			static Charset s_defaultCharset;
			static OutPrecision s_defaultOutPrecision;
			static ClipPrecision s_defaultClipPrecision;
			static Quality s_defaultQuality;
			static Pitch s_defaultPitch;
			static Family s_defaultFamily;
			static std::string s_defaultFontName;

		// Object
		private:
			// Properties
			HFONT handle{ nullptr };

		public:
			// Properties
			int height{ s_defaultWidth };
			int width{ s_defaultHeight };
			int angle{ s_defaultAngle };
			int orientation{ s_defaultOrientation };
			Weight fontWeight{ s_defaultFontWeight };
			bool italic{ s_defaultItalic };
			bool strikeOut{ s_defaultStrikeOut };
			bool underline{ s_defaultUnderline };
			Charset charset{ s_defaultCharset };
			OutPrecision outPrecision{ s_defaultOutPrecision };
			ClipPrecision clipPrecision{ s_defaultClipPrecision };
			std::string fontName{ s_defaultFontName };
			Quality quality{ s_defaultQuality };
			Pitch fontPitch{ s_defaultPitch };
			Family fontFamily{ s_defaultFamily };

			// Constructor / Destructor
			Font() = default;
			Font(const Font& other) = delete;
			Font(Font&& other) = delete;
			Font& operator=(const Font& other) = delete;
			Font& operator=(Font&& other) = delete;
			~Font();

			// Getters
			HFONT getHandle();

			// Functions
			HFONT createHandle();
			bool destroyHandle();
	};

	// Functions | Font::Weight
	constexpr Font::Weight operator|(Font::Weight a, Font::Weight b) {
		return static_cast<Font::Weight>(static_cast<int>(a) | static_cast<int>(b));
	}
	constexpr Font::Weight operator&(Font::Weight a, Font::Weight b) {
		return static_cast<Font::Weight>(static_cast<int>(a) & static_cast<int>(b));
	}
	constexpr Font::Weight& operator|=(Font::Weight& a, Font::Weight b) {
		a = a | b;
		return a;
	}
	constexpr Font::Weight& operator&=(Font::Weight& a, Font::Weight b) {
		a = a & b;
		return a;
	}
	constexpr Font::Weight operator~(Font::Weight a) {
		return static_cast<Font::Weight>(~static_cast<int>(a));
	}

	// Functions | Font::Pitch & Font::Family
	constexpr Font::Pitch operator|(Font::Pitch a, Font::Family b) {
		return static_cast<Font::Pitch>(static_cast<int>(a) | static_cast<int>(b));
	}
}
