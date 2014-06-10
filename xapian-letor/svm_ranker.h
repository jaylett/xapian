/* svmranker.h: The svmranker file.
 *
 * Copyright (C) 2012 Parth Gupta
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#ifndef SVMRANKER_H
#define SVMRANKER_H

#include <xapian.h>
#include <xapian/intrusive_ptr.h>
#include <xapian/types.h>
#include <xapian/visibility.h>

#include "ranker.h"
#include "ranklist.h"
#include "featurevector.h"

#include <list>
#include <map>
#include <libsvm/svm.h>

using namespace std;

namespace Xapian {

class XAPIAN_VISIBILITY_DEFAULT SVMRanker: public Ranker {

    struct svm_model *model;

  public:
    SVMRanker();

    void train_model();

    void save_model_to_file();

    void load_model_from_file(const std::string & model_file);

    Xapian::RankList rank(Xapian::RankList & rl);
    
};

}
#endif /* SVMRANKER_H */
