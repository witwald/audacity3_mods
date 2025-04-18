/*
* Audacity: A Digital Audio Editor
*/
#pragma once

#include "trackedit/itrackeditclipboard.h"

#include "modularity/ioc.h"
#include "context/iglobalcontext.h"

namespace au::trackedit {
class Au3TrackeditClipboard : public ITrackeditClipboard
{
    muse::Inject<au::context::IGlobalContext> globalContext;

public:
    std::vector<TrackData> trackDataSource() const override;
    std::vector<TrackData> trackDataCopy() const override;
    TrackData trackData(size_t i) const override;
    void clearTrackData() override;
    bool trackDataEmpty() const override;
    size_t trackDataSize() const override;
    void addTrackData(const TrackData& trackData) override;

    void setMultiSelectionCopy(bool newValue) override;
    bool isMultiSelectionCopy() const override;

private:
    friend class Au3TrackEditClipboardTests;

    static std::set<int64_t> getGroupIDs(const std::vector<TrackData>& tracksData);
    std::vector<int64_t> createNewGroupIDs(const std::set<int64_t>& groupIDs) const;
    static void updateTracksDataWithIDs(const std::vector<TrackData>& tracksData, const std::set<int64_t>& groupIDs,
                                        const std::vector<int64_t>& newGroupIDs);

    std::vector<TrackData> m_tracksData;

    bool m_isMultiSelectionCopy = false;
};
}
