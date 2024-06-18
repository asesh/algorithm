//
//  path_finding.h
//  algorithm
//
//  Created by Asesh Shrestha on 9/26/20.
//  Copyright © 2020 Asesh Shrestha. All rights reserved.
//

#ifndef PATH_FINDING_H
#define PATH_FINDING_H

void draw_grid(int32_t row, int column) {
	for(int32_t row_count = 0; row_count < row; row_count++) {
		for(int32_t column_count = 0; column_count < column; column_count++) {
			std::cout<<"|"<<"\t";
		}
		std::cout<<std::endl;
	}
}

#endif /* PATH_FINDING_H */
