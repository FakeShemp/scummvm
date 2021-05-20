#include "base/plugins.h"
#include "engines/advancedDetector.h"

namespace KiriKiri2 {
static const PlainGameDescriptor kiriKiri2Games[] = {
	{ 0, 0 }
};


static const ADGameDescription gameDescriptions[] = {
	AD_TABLE_END_MARKER
};
}

class KiriKiri2MetaEngineDetection : public AdvancedMetaEngineDetection {
public:
	KiriKiri2MetaEngineDetection() : AdvancedMetaEngineDetection(KiriKiri2::gameDescriptions, sizeof(ADGameDescription), KiriKiri2::kiriKiri2Games) {
	}

	const char *getEngineId() const override {
		return "kirikiri2";
	}

	const char *getName() const override {
		return "KiriKiri 2";
	}

	const char *getOriginalCopyright() const override {
		return "Copyright (C) W.Dee";
	}
};

REGISTER_PLUGIN_STATIC(KIRIKIRI2_DETECTION, PLUGIN_TYPE_ENGINE_DETECTION, KiriKiri2MetaEngineDetection);